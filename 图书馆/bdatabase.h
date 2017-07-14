#ifndef _bdatabase_h_
#define _bdatabase_h_
#include "book.h"
#include <iostream>
using namespace std;
const int Maxb = 100;				//最大图书数量
class BDatabase				//图书库类
{
private:
	int top;				//图书记录指针
	Book book[Maxb];				//图书记录
public:
	BDatabase();				//构造函数初始化：读文件
	void clear();				//全部删除
	void clearone(int bookid);			//删除一本图书
	void chbook(int n);         //更改一本书的信息
	int addbook(int n, char *na);				//添加图书
	Book *query(int bookid);				//查找图书
	void list();				//输出图书信息
	void bookdata();				//图书库维护
	~BDatabase();				//析构函数：写文件
};
#endif