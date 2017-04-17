 ///
 /// @file    log4cpp3.cc
 /// @author  heartinharbin
 /// @date    2017-04-14 20:23:21
 ///
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::ostringstream;

int main(){
	log4cpp::PatternLayout *ptn1 = new log4cpp::PatternLayout();
	ptn1->setConversionPattern("%d %c [%p] : %m%n");

	log4cpp::PatternLayout *ptn2 = new log4cpp::PatternLayout();
	ptn2->setConversionPattern("%d %c [%p] : %m%n");

	log4cpp::FileAppender *pfileAp = new log4cpp::FileAppender("fileApd", "wd.log");
	pfileAp->setLayout(ptn1);

	log4cpp::RollingFileAppender *prfileAp = 
		new log4cpp::RollingFileAppender(
				"rollingfileAp",
				"rollingwd.log",
				5 * 1024,
				1);
	prfileAp->setLayout(ptn2);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	log4cpp::Category & debugCat = root.getInstance("DebugCat");
	debugCat.addAppender(pfileAp);
	debugCat.addAppender(prfileAp);
	debugCat.setPriority(log4cpp::Priority::DEBUG);

	for(size_t idx = 0; idx != 100; ++idx){
		ostringstream oss;
		oss << idx << ":Root Error Message!";
		debugCat.error(oss.str());
	}

	log4cpp::Category::shutdown();

	return 0;
}









