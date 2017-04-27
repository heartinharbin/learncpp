 ///
 /// @file    RssReader.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 10:22:57
 ///
 
#include "tinyxml2.h"

#include <boost/regex.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ostringstream;
using namespace tinyxml2;

struct Webpage
{
	string _docid;
	string _title;
	string _link;
	string _content;
};

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

class RssReader
{
	
public:
	RssReader();

	void loadFile(const string & filename);

	void dump(const string & filename);

private:
	void parse(XMLDocument & doc);

private:
	int _totalCount;
	vector<Webpage> _pages;
	const static int _kSize = 500;
};

RssReader::RssReader()
: _totalCount(0)
{
	_pages.reserve(_kSize);
}


void RssReader::loadFile(const string & filename)
{
	XMLDocument doc;
	doc.LoadFile(filename.c_str());
	XMLError errorId = doc.ErrorID();
	if(errorId)
	{
		cout << "load file error!" << endl;
		return ;
	}

	parse(doc);
}

void RssReader::parse(XMLDocument & doc)
{
	XMLElement * root = doc.FirstChildElement();
	XMLElement * item = root->FirstChildElement("channel")->FirstChildElement("item");

	for(; item; item = item->NextSiblingElement())
	{
		
		const char * itemTitle = item->FirstChildElement("title")->GetText();
		const char * itemLink = item->FirstChildElement("link")->GetText();
		XMLElement * contentEncoded = item->FirstChildElement("content:encoded");
		XMLElement * description = item->FirstChildElement("description");
		
		const char * itemContent = NULL;
		if(contentEncoded)
		{
			cout << "1111" << endl;
			itemContent = contentEncoded->GetText();
		}else
		{
			cout << "2222 " << endl;
			itemContent = description->GetText();
		}

		//匹配所有的html标签
		boost::regex reg("<.*?>");
		string content = boost::regex_replace(string(itemContent), reg, string(""));
		cout << "-------" << endl;
		cout << content << endl;
		cout << content << endl;
		cout << "[[[[[-------" << endl;

		Webpage webpage;
		webpage._docid = int2str(++_totalCount);
		webpage._title = itemTitle ? itemTitle : string("");
		webpage._link = itemLink ? itemLink : string("");
		webpage._content = content;
		_pages.push_back(webpage);
	}
}
	

//方式一：自行进行拼接
void RssReader::dump(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return;
	}

	auto it = _pages.begin();
	for(; it != _pages.end(); ++it)
	{
		string doc;
		doc.append("<doc>\n\t<docid>")
		   .append(it->_docid).append("</docid>\n\t<title>")
		   .append(it->_title).append("</title>\n\t<link>")
		   .append(it->_link).append("</link>\n\t<content>")
		   .append(it->_content).append("</content>\n</doc>\n");
		ofs << doc;
	}
	ofs.close();
}


int main(void)
{
	RssReader reader;
	reader.loadFile("coolshell.xml");
	reader.dump("pagelib.dat");

	return 0;
}
