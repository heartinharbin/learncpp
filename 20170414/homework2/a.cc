#include <cstdio>  
  
//�����ӡ�꣬���ڴ�ӡ��Ϣǰ�����ļ������кš�������  
  
//�˺�չ����������printf("123"),printf("456");  
#define TRACE_CMH_1 (printf("%s(%d)-<%s>: ",__FILE__, __LINE__, __FUNCTION__), printf)  
  
//�˺�չ����������printf("%d""%d", 1, 2);  
#define TRACE_CMH_2(fmt,...) \  
    printf("%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
  
//ע�����ڵ�һ����TRACE_CMH_1����������printf������Ч��û�еڶ�����ߡ�  
//���������֧��C99��׼�Ļ��������õڶ����ꡣ  

int count = 1;
  
class CBase  
{  
public:  
    CBase()  
    {  
        //��ӡ��ǰ�������ļ����кš��������Լ�������Ϣ
		TRACE_CMH_2("BASE: [%d]\n", count++);  
    }  
};  
  
class CSub : public CBase  
{  
public:  
    CSub()  
    {  
        //��ӡ��ǰ�������ļ����кš��������Լ�������Ϣ��  
        TRACE_CMH_1("SUB: [%d]\n", count++);
    }  
};  
  
int main(int argc, char **argv)  
{  
    CSub sub;  
  
    return 0;  
}  