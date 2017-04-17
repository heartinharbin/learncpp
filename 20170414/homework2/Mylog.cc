 ///
 /// @file    Mylog.cc
 /// @author  heartinharbin
 /// @date    2017-04-14 21:10:16
 ///
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream>
using std::cout;
using std::endl;

class Mylog
{
public:	
	static Mylog *getInstance(){
		if(NULL == _pInstance){
			_pInstance = new Mylog;
		}
		return _pInstance;
	}

	static void destroy(){
		if(_pInstance)
			delete _pInstance;
	}

	static void warn(const char *msg){
		root.warn(msg);
	}
	static void error(const char *msg){
		root.error(msg);
	}
	static void debug(const char *msg){
		root.debug(msg);
	}
	static void info(const char *msg){
		root.info(msg);	
	}
private:
	Mylog(){
		cout << "Mylog()" << endl;
		log4cpp::PatternLayout *ptn1 = new log4cpp::PatternLayout();
		ptn1->setConversionPattern("%d %c [%p] : %m%n");

		log4cpp::PatternLayout *ptn2 = new log4cpp::PatternLayout();
		ptn2->setConversionPattern("%d %c [%p] : %m%n");

		log4cpp::OstreamAppender *pOsAp = new log4cpp::OstreamAppender("oStreamAppender", &cout);
		pOsAp->setLayout(ptn1);

		log4cpp::RollingFileAppender *prfileApd =
			new log4cpp::RollingFileAppender(
					"rollingfileApd",
					"rollingwd.log",
					5 * 1024,
					1);
		prfileApd->setLayout(ptn2);
		
		root = log4cpp::Category::getRoot();
		root.addAppender(pOsAp);
		root.addAppender(prfileApd);
		root.setPriority(log4cpp::Priority::DEBUG);
	}
	~Mylog(){
		cout << "~Mylog()" << endl;
	}
	//Mylog(const Mylog &);
	//Mylog & operator = (const Mylog&);
private:
	static Mylog * _pInstance;
	static log4cpp::Category root;

};//end of class Mylog
