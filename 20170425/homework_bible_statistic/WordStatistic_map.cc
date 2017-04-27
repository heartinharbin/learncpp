 ///
 /// @file    WordStatistic2.cc
 /// @author  heartinharbin
 /// @date    2017-04-14 13:57:46
 ///
#include <ctype.h>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <iostream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;
using std::ios;
using std::setw;
using std::setiosflags;
const int HASH_SIZE = 26;

/*
typedef struct{
	string str;
	int count;
}word, *pword;
*/
class WordStatistic{
public:
	WordStatistic()
	:w_count(0){
		cout << "WordStatistic()" << endl;
	}

	~WordStatistic(){
		cout << "~WordStatistic()" << endl;
	}

	void readFile(const std::string filename){
		ifstream ifs(filename.c_str());
		if(!ifs.good()){
			cout << "open file error!" << endl;
		}
		string str;
		int ans;
		while(ifs >> str){
			if(isalpha(str[0])){
				++w_count;
				ans = str[0] - 'a';
				++w_hash_dic[ans][str];
			}
		}
		cout << "w_count:" << w_count << endl;
		ifs.close();
	}
	void writeFile(const std::string filename){
		ofstream ofs(filename.c_str(), std::ios::app);
		if(!ofs.good()){
			cout << "file open error!" << endl;
		}
		int i;
		for(i = 0; i < HASH_SIZE; i++){
			for(const auto &w : w_hash_dic[i]){
				ofs << setiosflags(ios::left) << setw(20) << w.first 
					<< setw(10) << w.second  << endl;
			}
		}
		ofs.close();
	}
private:
	//......
	map<string, size_t> w_hash_dic[26];
	int w_count;
};//end of class WordStatistic


int main(){
	WordStatistic ws;
	ws.readFile("The_Holy_Bible.txt");
	ws.writeFile("result.txt");
	
	return 0;
}
