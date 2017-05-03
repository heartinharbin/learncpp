 ///
 /// @file    testQuery.cc
 /// @author  heartinharbin
 /// @date    2017-05-01 21:01:17
 ///
#include <assert.h>
#include <ctype.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::replace_if;

static_assert(sizeof(void*) == 8, "not supported");

class TestQuery{
public:
	TextQuery();
	void readFile(const string & filename);
	void query(const string & word);
private:
	static const int kInit = 178;
	vector<string> _lines;
	map<string, int> _dict;
	map<string, set<int> > _word2Line;
};//end of class TestQuery

TestQuery::TestQuery(){
	_lines.reserve(kInit);
}

struct Notalpha{
	bool operator()(char ch) const{
		return (!isalpha(ch));
	}
};

struct IsAlpha : public std::unary_function<char, bool>{
	bool operator()(char ch) const{
		return (isalpha(ch));
	}
};







int main(void){
	return 0;
}

