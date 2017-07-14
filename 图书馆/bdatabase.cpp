#include <fstream>
#include <iostream>
#include <iomanip>
#include "bdatabase.h"
using namespace std;
BDatabase::BDatabase()
{
	Book s;
	top = -1;
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file)
			break;
		top++;
		book[top] = s;
	}
	file.close();
}
void BDatabase::clear()
{
	top = -1;
	cout << "已删除！" << endl;
}
void BDatabase::clearone(int bookid)			//删除一本图书信息
{
	for (int i = 0; i <= top; i++)
	if (book[i].getnumber() == bookid&&book[i].getnote() == 0)
	{
		book[i].delbook();
		cout << "已删除！" << endl;
	}
}
Book *BDatabase::query(int bookid)
{
	for (int i = 0; i <= top; i++)
	if (book[i].getnumber() == bookid&&book[i].getnote() == 0)
		return &book[i];
	return NULL;
}
int BDatabase::addbook(int n, char *na)
{
	Book *p = query(n);
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnumber() == n&&book[i].getnote() == 1)
		{
			cout << "该书籍曾存在且已被删除！" << endl;
			book[i].addbook(n, na);
			cout << "已覆盖新信息！" << endl;
			p = &book[i];
			return 1;
		}
	}
	if (p == NULL)
	{
		top++;
		book[top].addbook(n, na);
		cout << "成功添加！" << endl;
		return 1;
	}
	if (p != NULL)
	{
		cout << "该编号已有书籍，不能新增！" << endl;
		return 1;
	}
	return 0;
}
void BDatabase::chbook(int n)			//更改一本书的信息
{
	char na[20];
	Book *p = query(n);
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnumber() == n&&book[i].getnote() == 1)
		{
			cout << "该编号书籍曾存在且已被删除！" << endl;
			cout << "请输入新的书名：";
			cin >> na;
			book[i].setname(na);
			p = &book[i];
			book[i].setnote();
			cout << "修改成功！" << endl;
			return;
		}
	}
	if (p == NULL)
	{
		cout << "该书不存在！" << endl;
		return;
	}
	cout << "输入新的书名：";
	cin >> na;
	p->setname(na);
	cout << "修改成功！" << endl;
}
void BDatabase::list()
{
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnote() == 1)
		{
			cout << setw(5) << book[i].getnumber() << "   该编号书籍已被删除！" << endl;
		}
		if (book[i].getnote() == 0)
			book[i].list();
	}
}
BDatabase::~BDatabase()
{
	fstream file;
	file.open("book.dat", ios::out | ios::binary);
	for (int i = 0; i <= top;i++)
	if (book[i].getnote() == 0)
		file.write((char *)&book[i], sizeof(book[i]));
	file.close();
}
void BDatabase::bookdata()
{
	int choice = 1;
	char bookname[25];
	int bookid;
	Book *b;
	while (choice != 0)
	{
		cout << "图书维护：" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cout << "请输入你要执行的操作对应编号：";
		cin >> choice;
		cout << "-------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "输入新增图书编号：";
			cin >> bookid;
			cout << "输入新增图书名：";
			cin >> bookname;
			addbook(bookid, bookname);
			break;
		case 2:cout << "输入要更改图书的编号：";
			cin >> bookid;
			chbook(bookid);
			break;
		case 3:cout << "输入要删除图书的编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			clearone(bookid);
			break;
		case 4:cout << "输入要查找图书的编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			b->list(); break;
		case 5:
			if (top == -1)
			{
				   cout << "暂无图书信息！" << endl;
				   break;
			}
			list(); break;
		case 6:clear();break;
		case 0:break;
		default:cout << "输入编号有误！"<<endl;
			break;
		}
	}
	system("cls");
	cout << "-------------------------------" << endl;
	cout << "欢迎进入“小小图书馆”管理软件" << endl;
	cout << "-------------------------------" << endl;
}