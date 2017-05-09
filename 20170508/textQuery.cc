 ///
 /// @file    textQuery.cc
 /// @author  heartinharbin
 /// @date    2017-05-08 11:21:17
 ///
 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ostream;
using std::ifstream;
using std::shared_ptr;
using std::istringstream;

inline string make_plural(size_t ctr, const string &word, const string ending){
	return (ctr == 1)? word : word + ending;
}


class QueryResult;

class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string> > file;
	map<string, shared_ptr<set<line_no>>> wm;
};//end of class TextQuery

TextQuery::TextQuery(ifstream &is)
: file(new vector<string>){
	string text;
	while(getline(is, text)){
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word){
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}



class QueryResult{
	friend ostream & print(ostream &, const QueryResult&);
public:
	using line_no = vector<string>::size_type;
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
	: sought(s), lines(p), file(f){}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};//end of class QueryResult


QueryResult TextQuery::query(const string &sought) const{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr){
	os << qr.sought << "occurs" << qr.lines->size() << " " 
	   << make_plural(qr.lines->size(), "time", "s") << endl;
	for(auto num : *qr.lines){
		os << "\t(line" << num + 1 << ") "
		   << *(qr.file->begin() + num) << endl;
	}
	return os;
}

void runQueries(ifstream &infile){
	TextQuery tq(infile);
	while(true){
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(void){
	ifstream ifs("passage.txt");
	runQueries(ifs);
	return 0;
}
