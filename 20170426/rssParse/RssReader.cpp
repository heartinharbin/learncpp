#include "RssReader.h"

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <boost/regex.hpp>
using namespace tinyxml2;

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ostringstream;


string int2str(int num){
	ostringstream oss;
	oss << num;
	return oss.str();
}



RssReader::RssReader()
:_totalCount(0){
	_rss.reserve(_kSize);
}

void RssReader::parseRss(const char* xmlPath){
	XMLDocument doc;
    if(doc.LoadFile(xmlPath)!=0)
    {
        cout<<"load xml file failed"<<endl;
        return;
    }
    XMLElement *root=doc.RootElement();
//	XMLElement *chanel=root->FirstChildElement("channel");
//	XMLElement *item=chanel->FirstChildElement("item");
	XMLElement *item = root->FirstChildElement("channel")->FirstChildElement("item");	
	while (item){
		rssItem ri;

		XMLElement *title = item->FirstChildElement("title");
		
		XMLElement *link = item->FirstChildElement("link");

		XMLElement *description = item->FirstChildElement("description");
		XMLElement *content = item->FirstChildElement("content:encoded");
		const char * contentTmp = NULL;
		if(content){
			contentTmp = content->GetText();
		}else{
			contentTmp = description->GetText();
		}
	
		boost::regex reg("<.*?>");
		string content_reg = boost::regex_replace(string(contentTmp), reg, string(""));

		ri._docid = int2str(++_totalCount);
		ri._title = title->GetText();
		ri._link = link->GetText();
		ri._content = content_reg;
		_rss.push_back(ri);

		item = item->NextSiblingElement();
	}
	
}

void RssReader::dump(const char* xmlPath){
	ofstream ofs(xmlPath, std::ios::out);
	if(!ofs.good()){
		cout << "ofstream open error!" << endl;
		return;
	}
	ofs.close();
	XMLDocument doc;
    int res=doc.LoadFile(xmlPath);
    /*
	 if(res!=0)
    {
        cout<<"load xml file failed"<<endl;
        return;
    }
	*/
//	XMLDeclaration* declaration=doc.NewDeclaration();//添加xml文件头申明
//	doc.InsertFirstChild(declaration);


    //XMLElement* root=doc.RootElement();
	/*
	vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl;
	*/
	for(auto ri : _rss){
		XMLElement* docNode = doc.NewElement("doc");
		doc.InsertEndChild(docNode);

		XMLElement* docid = doc.NewElement("docid");
		XMLText* docidText=doc.NewText(ri._docid.c_str());
		docid->InsertEndChild(docidText);
		docNode->InsertEndChild(docid);	

		XMLElement* title = doc.NewElement("title");
		XMLText* titleText=doc.NewText(ri._title.c_str());
		title->InsertEndChild(titleText);
		docNode->InsertEndChild(title);	
		
		XMLElement* link = doc.NewElement("link");
		XMLText* linkText=doc.NewText(ri._link.c_str());
		link->InsertEndChild(linkText);
		docNode->InsertEndChild(link);	
/*
		XMLElement* description = doc.NewElement("description");
		XMLText* descriptionText=doc.NewText(ri._description.c_str());
		description->InsertEndChild(descriptionText);
		docNode->InsertEndChild(description);	
*/
		XMLElement* content = doc.NewElement("content");
		XMLText* contentText=doc.NewText(ri._content.c_str());
		content->InsertEndChild(contentText);
		docNode->InsertEndChild(content);	
	}
	doc.SaveFile(xmlPath);
}



int main(){
	RssReader rr;
	rr.parseRss("coolshell.xml");
	rr.dump("pagelib.dat");
	return 0;
}
