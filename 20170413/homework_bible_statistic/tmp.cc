 ///
 /// @file    dictionary.cc
 /// @author  book123445(342846350@qq.com)
 /// @date    2017-04-13 21:49:24
 ///
#include <stdio.h>
#include <string.h>
#include <string> 
#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
typedef struct{
	string w;
	int con;

}word;

class WordStatistic{
	public:
		int readFile(const string filename)
	
		{
			dic.reserve(1000);
			//char name[50]={0};
			//strcpy(name,filename);
			word tmp;
			int i=0;
			//cout<<"filename "<<filename.data()<<endl;
		#if 1
			ifstream ifs(filename.data());
			if(!ifs.good())
			{
				cout<<"open "<<filename<<" error"<<endl;
				return -1;
			}
			while(ifs>>tmp.w,!ifs.eof())
			{
				if((tmp.w[0]>='a'&&tmp.w[0]<='z')||(tmp.w[0]>='A'&&tmp.w[0]<='Z'))
				{
					for(i=0;i<dic.size();i++)
					{
						if(dic[i].w==tmp.w)
						{
							dic[i].con++;
							break;
						}
						
					}
					if(i==dic.size())
					{
						tmp.con=1;
						dic.push_back(tmp);
					}
				}
			}
			ifs.close();
			return 0;
#endif
		}
#if 1
		int writeFile(const string filename)
		{
			int i;
			
			string newname="dic_"+filename;
			//char newname[50]={0};
			//sprintf(newname,"dic_%s",filename);
			ofstream ofs(newname.data());
			//cout<<"newname "<<newname.data()<<endl;
			if(!ofs.good())
			{
				cout<<"open "<<newname<<" error"<<endl;
				return -1;
			}
			for(i=0;i<dic.size();i++)
			{
				ofs<<dic[i].w<<"  "<<dic[i].con<<endl;
			}

			ofs.close();
			return 0;

		}
#endif
	private:
		vector<word> dic;
};

int main()
{
	int ret;
	string filename;
	//char filename[50]={0};
	WordStatistic f;
	cout<<"please enter the filename"<<endl;
	//scanf("%s",filename);
	//cout<<"main filename"<<filename<<endl;
	cin>>filename;
	ret=f.readFile(filename);
	if(ret==-1)
	{
		return -1;
	}
	ret=f.writeFile(filename);
	if(ret==-1)
	{
		return -1;
	}

	return 0;
}