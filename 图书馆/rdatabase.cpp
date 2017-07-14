#include <fstream>
#include <iomanip>
#include <iostream>
#include "rdatabase.h"
using namespace std;
RDatabase::RDatabase()				//构造函数初始化
{
	Reader s;			//定义一个Reader类的变量，包含成员数据和成员函数
	top = -1;											
	ifstream file;
	file.open("reader.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char *)&s, sizeof(s));
		if (!file)
			break;
		top++; 
		read[top] = s;
	}
	file.close();										
}
void RDatabase::clear() 			//删除所有读者信息
{
	top = -1;
	cout << "已删除！" << endl;
}
void RDatabase::clearone(int readerid)			//删除一个读者信息
{
	for (int i = 0; i <= top; i++)
	if (read[i].getnumber() == readerid&&read[i].getnote() == 0)
	{
		read[i].delreader();
		cout << "已删除！" << endl;
	}
}
Reader *RDatabase::query(int readerid)               	//按编号查找，返回地址
{
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == readerid&&read[i].getnote() == 0)
			return &read[i];
	}
	return NULL;			
}
int RDatabase::addreader(int n, char *na)			//添加新读者
{
	Reader *p = query(n);            			
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == n&&read[i].getnote() == 1)
		{
			cout << "该读者曾存在且已被删除！" << endl;
			read[i].addreader(n, na);
			cout << "已覆盖新信息！" << endl;
			p = &read[i];
			return 1;
		}
	}
	if (p == NULL)
	{
		top++;
		read[top].addreader(n, na);	
		cout << "成功添加！" << endl;
		return 1;
	}
	if (p != NULL)
	{
		cout << "该编号已有读者，不能新增！" << endl;
		return 1;
	}
	return 0;
}
void RDatabase::chreader(int n)			//更改一个读者信息
{
	char na[20];
	Reader *p = query(n);
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == n&&read[i].getnote() == 1)
		{
			cout << "该编号读者曾存在且已被删除！" << endl;
			cout << "请输入新的姓名：";
			cin >> na;
			read[i].setname(na);
			read[i].setnote();
			p = &read[i];
			cout << "修改成功！" << endl;
			return;
		}
	}
	if (p == NULL)
	{
		cout << "该读者不存在！" << endl;
		return;
	}
	cout << "输入新的姓名：";
	cin >> na;
	p->setname(na);
	cout << "修改成功！" << endl;
}
void RDatabase::list()			//显示所有读者信息
{
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnote() == 1)
		{
			cout << setw(5)<<read[i].getnumber()<<"   该编号读者已被删除！" << endl;
		}
		if (read[i].getnote()==0)
			read[i].list();               			
	}
}
RDatabase::~RDatabase()			//析构函数
{
	fstream file;              			
	file.open("reader.dat", ios::out | ios::binary);
	for (int i = 0; i <= top;i++)
	if (read[i].getnote() == 0)
		file.write((char *)&read[i], sizeof (read[i]));
	file.close();							
}
void RDatabase::readerdata()
{
	int choice = 1;
	char readername[20];
	int readerid;
	Reader *r;
	while (choice != 0)
	{
		cout << "读者维护：" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cout << "请输入你要执行的操作对应编号：";
		cin >> choice;
		cout << "--------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "输入新增读者编号：";
			cin >> readerid;
			cout << "输入新增读者姓名：";
			cin >> readername;
			addreader(readerid, readername);                 
			break;
		case 2:cout << "输入要更改读者的编号：";		
			cin >> readerid;
			chreader(readerid);
			break;
		case 3:cout << "输入要删除读者的编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			clearone(readerid);
			break;
		case 4:cout << "输入要查找读者的编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			r->list(); break;
		case 5:
			if (top == -1)
			{
				cout << "暂无读者信息！" << endl;
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