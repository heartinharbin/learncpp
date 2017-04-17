#include "WordStatistic.h"


class WordStatistic
{
public:
	//���캯��
	WordStatistic()
	:w_all_count(0)
	,w_n_count(0)
	,w_word_count(0){
		int i;
		pwd w;
		cout << "WordStatistic()" << endl;
		//��ʼ��ָ������
		for(i = 0; i < CENSUS_SIZE; i++){
			w = (pwd)calloc(1, sizeof(wd));
			w->count = 0;
			w->next = NULL;
			census[i] = w;
		}
	}

	//��������
	~WordStatistic(){
		int i;
		pwd ppre, pcur;
		cout << "~WordStatistic()" << endl;
		for(i = 0; i < CENSUS_SIZE; i++){
			pcur = census[i];
			while(NULL != pcur){
				ppre = pcur;
				pcur = pcur->next;
				free(ppre);
				ppre = NULL;//��ֹҰָ��
			}
		}
	}

	void readFile(const std::string filename){
		char c;
		int word_temp_count;
		char word_temp[20];
		int flag = OUT;
		pwd w;
		int i;
	
		//��ʼ��ָ������
		for(i = 0; i < CENSUS_SIZE; i++){
			w = (pwd)calloc(1, sizeof(wd));
			w->count = 0;
			w->next = NULL;
			census[i] = w;
		}
		
		ifstream ifs(filename.c_str());//�ļ�������Ҫ���ļ��Ǵ��ڵ�
		if(!ifs.good())
		{
			cout << "ifstream open error!" << endl;
			return;
		}
		
		memset(word_temp, 0 , sizeof(word_temp));
		word_temp_count = 0;
		while(ifs.get(c)){
			++w_all_count;
			if(c == '\n'){
					++w_n_count;
			}
			if(!isalpha(c)){
				if(IN == flag){
					word_temp[word_temp_count] = '\0';
					list_insert(word_temp);
					memset(word_temp, 0 , sizeof(word_temp));
					word_temp_count = 0;
				}
				flag = OUT;
			}else if(OUT == flag){
				flag = IN;
				word_temp[word_temp_count++] = c;
				++w_word_count;
			}else if(IN == flag){
				word_temp[word_temp_count++] = c;
			}
		}
		//����EOFǰ����һ�����ʵ����
		if(IN == flag){
			word_temp[word_temp_count] = '\0';
			list_insert(word_temp);
		}

		//�����1�����У�����Ϊ2
		if(0 == w_n_count && 0 != w_all_count){
			++w_n_count;
		}else if(w_n_count != 0){
			++w_n_count;
		}

		cout << "char count:" << w_all_count << endl
			<< "line count:" << w_n_count << endl
			<< "word count:" << w_word_count << endl;
		ifs.close();
		return;
	}
	void writeFile(const std::string filename){
		pwd pcur;
		int i;
		ofstream ofs(filename.c_str(), std::ios::app);
		if(!ofs.good())
		{
			cout << "ofstream open error!" << endl;
			return;
		}
		for(i = 0; i < CENSUS_SIZE; i++){
			pcur = census[i]->next;
			while(NULL != pcur){
				ofs << setiosflags(ios::left) << setw(20) << pcur->str 
					<< setw(10) << pcur->count << endl;
				pcur = pcur->next;
			}
		}
		ofs.close();
	}

private:
	//����ȡ���ĵ��ʲ����Ӧ������
	void list_insert(char *s){
		int len = strlen(s);
		int ans = tolower(s[0]) - 'a';
		pwd pnew;
		pwd pcur, ppre;
		int flag;
		ppre = census[ans];
		pcur = census[ans]->next;
	
		while(NULL != pcur){
			flag = strcmp(s, pcur->str);
			if(0 == flag){
				pcur->count++;
				break;
			}else if(flag > 0){
				ppre = pcur;
				pcur = pcur->next;
			}else{
				pnew = (pwd)calloc(1, sizeof(wd));
				pnew->count = 1;
				strcpy(pnew->str, s);
				pnew->next = pcur;
				ppre->next = pnew;
				break;
			}
		}
		if(NULL == pcur){
			pnew = (pwd)calloc(1, sizeof(wd));
			pnew->count = 1;
			strcpy(pnew->str, s);
			pnew->next = NULL;
			ppre->next = pnew;
		}
	}


private:
	int w_all_count;	//�ַ���ͳ��
	int w_n_count;		//����ͳ��
	int w_word_count;	//������ͳ��
	pwd census[26];		//26����ͷ��ĸ��Ӧ26������
};

int main(){
	WordStatistic ws;
	cout << "start process ..." << endl;
	ws.readFile("/home/mustafa/learncpp/20170413/homework_bible_statistic/The_Holy_Bible.txt");
	ws.writeFile("/home/mustafa/learncpp/20170413/homework_bible_statistic/result.txt");
	cout << "end process ..." << endl;
}
