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
	cout << "��ɾ����" << endl;
}
void BDatabase::clearone(int bookid)			//ɾ��һ��ͼ����Ϣ
{
	for (int i = 0; i <= top; i++)
	if (book[i].getnumber() == bookid&&book[i].getnote() == 0)
	{
		book[i].delbook();
		cout << "��ɾ����" << endl;
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
			cout << "���鼮���������ѱ�ɾ����" << endl;
			book[i].addbook(n, na);
			cout << "�Ѹ�������Ϣ��" << endl;
			p = &book[i];
			return 1;
		}
	}
	if (p == NULL)
	{
		top++;
		book[top].addbook(n, na);
		cout << "�ɹ���ӣ�" << endl;
		return 1;
	}
	if (p != NULL)
	{
		cout << "�ñ�������鼮������������" << endl;
		return 1;
	}
	return 0;
}
void BDatabase::chbook(int n)			//����һ�������Ϣ
{
	char na[20];
	Book *p = query(n);
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnumber() == n&&book[i].getnote() == 1)
		{
			cout << "�ñ���鼮���������ѱ�ɾ����" << endl;
			cout << "�������µ�������";
			cin >> na;
			book[i].setname(na);
			p = &book[i];
			book[i].setnote();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	if (p == NULL)
	{
		cout << "���鲻���ڣ�" << endl;
		return;
	}
	cout << "�����µ�������";
	cin >> na;
	p->setname(na);
	cout << "�޸ĳɹ���" << endl;
}
void BDatabase::list()
{
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnote() == 1)
		{
			cout << setw(5) << book[i].getnumber() << "   �ñ���鼮�ѱ�ɾ����" << endl;
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
		cout << "ͼ��ά����" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cout << "��������Ҫִ�еĲ�����Ӧ��ţ�";
		cin >> choice;
		cout << "-------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "��������ͼ���ţ�";
			cin >> bookid;
			cout << "��������ͼ������";
			cin >> bookname;
			addbook(bookid, bookname);
			break;
		case 2:cout << "����Ҫ����ͼ��ı�ţ�";
			cin >> bookid;
			chbook(bookid);
			break;
		case 3:cout << "����Ҫɾ��ͼ��ı�ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			clearone(bookid);
			break;
		case 4:cout << "����Ҫ����ͼ��ı�ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			b->list(); break;
		case 5:
			if (top == -1)
			{
				   cout << "����ͼ����Ϣ��" << endl;
				   break;
			}
			list(); break;
		case 6:clear();break;
		case 0:break;
		default:cout << "����������"<<endl;
			break;
		}
	}
	system("cls");
	cout << "-------------------------------" << endl;
	cout << "��ӭ���롰ССͼ��ݡ��������" << endl;
	cout << "-------------------------------" << endl;
}