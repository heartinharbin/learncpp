 ///
 /// @file    associativeContainer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 15:11:11
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;
using std::pair;

template <typename Container>
void display(Container & c)
{
	typename Container::iterator it;
	for(it = c.begin(); it != c.end(); ++it)
	{
		cout << it->first << "-->" << it->second << endl;
	}
}


void test0(void)
{
	map<int, string> mapIntStr{
		std::make_pair(1, "AA"),
		std::make_pair(2, "BB")
	};
	
	pair<int, string> elem(3, "XX");

	//map<int, string>::iterator it = mapIntStr.begin();
	//pair<map<int, string>::iterator, bool> ret = mapIntStr.insert(elem);
	auto ret = mapIntStr.insert(elem);

	if(ret.second)
	{
		cout << "添加成功:"
			 << ret.first->first << " ---> "
			 << ret.first->second << endl;
	}
	else
	{
		cout << "添加失败，原容器中已有相同关键字的元素!" << endl;
	}

	display(mapIntStr);
}

void test1(void)
{
	multimap<int, string> mapIntStr{
		std::make_pair(1, "AA"),
		std::make_pair(2, "BB")
	};
	
	pair<int, string> elem(2, "XX");

	map<int, string>::iterator it = mapIntStr.insert(elem);

	cout << it->first << " ---> " << it->second << endl;

	display(mapIntStr);
}


int main(void)
{
	test0();
	cout << "======" << endl;
	test1();

	return 0;
}
