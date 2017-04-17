#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::endl;


int main(void)
{
	//		sCtrl + d　代表输入结束
	//Ctrl + c  终止程序
	//Ctrl + z  将程序挂起，放到后台运行
	int ival;
//	while(cin >> ival, !cin.eof())
	while(cin >> ival)
	{
		if(cin.bad())
		{
			cout << "IO stream corrupted!" << endl;
			return -1;
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input an integer:" << endl;
			continue;
		}

		cout << "ival = " << ival << endl;
	}
	return 0;
}


