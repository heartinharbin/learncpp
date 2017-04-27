#ifndef __RSSREADER_H__
#define __RSSREADER_H__

#include "tinyxml2.h"
#include <stdio.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

typedef struct RssItem
{
	string _docid;
	string _title;
    string _link;
    string _description;
    string _content;
}rssItem;
    
class RssReader
{
public:
    RssReader();
        
    void parseRss(const char* xmlPath);//½âÎö
    void dump(const char* xmlPath);//Êä³ö
private:
	int _totalCount;
    vector<RssItem> _rss;
	const static int _kSize = 520;

};   

#endif
