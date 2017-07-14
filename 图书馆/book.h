#ifndef _book_h_
#define _book_h_
#include <iostream>
using namespace std;
class Book						//图书类
{
private:
	int note;				//删除标记（1：已删 0：未删）
	int number;				//图书编号
	char name[25];				//书名
	int onshelf;				//上架标记
public:
	Book()
	{}
	char *getname();				//获得书名
	int getnote();				//获得删除标记
	int getnumber();				//获得图书编号
	void setnote();				//设置未删标记
	void setname(char na[]);				//设置书名
	void delbook();				//删除图书
	void addbook(int n, char *na);				//添加图书
	int borrowbook();				//借书操作
	void borrbook();
	void retbook();				//还书操作
	void list();				//输出图书
};
#endif