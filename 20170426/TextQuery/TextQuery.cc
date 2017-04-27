 ///
 /// @file    TextQuery.cc
 /// @author  heartinharbin
 /// @date    2017-04-27 09:47:11
 ///
 
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::string;
using std::ifstream;
using std::stringstream;

class TextQuery{
public:
	TextQuery();

	~TextQuery();

	void readFile(const string filename);

	void query(const string & word);
private:
	vector<string> _lines;
	map<string, set<int> > _word2Line;
	map<string, int> _wordFreq;

};///end of class TextQuery

TextQuery::TextQuery(){
	cout << "TextQuery()" << endl;
	_lines.reserve(1000);
}

TextQuery::~TextQuery(){
	cout << "~TextQuery()" << endl;
}

void TextQuery::readFile(const string filename){
	ifstream ifs(filename.c_str());
	if(!ifs.good()){
		cout << "file open error" << endl;
	}
	string tmpline;
	string tmpword;
	stringstream ss;
	int linenum = 0;
	while(getline(ifs, tmpline)){
	//	cout << tmpline << endl;
		++linenum;
		_lines.push_back(tmpline);
		ss.clear();
		ss << tmpline;
		while(ss >> tmpword){
			++_wordFreq[tmpword];
			_word2Line[tmpword].insert(linenum);
		}
	}
	ifs.close();
}

void TextQuery::query(const string &word){
	map<string, int>::iterator it = _wordFreq.find(word);
	if(it != _wordFreq.end()){
		cout << word << " occurs " << it->second << " times:" << endl;
		for(const auto &v : _word2Line[word]){
			cout << "    " << "(line " << v << ")" << _lines[v-1] << endl;
		}
	}
}

void test1(void){
	TextQuery tq;
	tq.readFile("china_daily.txt");
	tq.query("and");
		
}

int main(void){
	test1();
	return 0;
}


