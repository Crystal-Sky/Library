#include <fstream>
#include <iomanip>
#include <iostream>
#include "rdatabase.h"
using namespace std;
RDatabase::RDatabase()				//���캯����ʼ��
{
	Reader s;			//����һ��Reader��ı�����������Ա���ݺͳ�Ա����
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
void RDatabase::clear() 			//ɾ�����ж�����Ϣ
{
	top = -1;
	cout << "��ɾ����" << endl;
}
void RDatabase::clearone(int readerid)			//ɾ��һ��������Ϣ
{
	for (int i = 0; i <= top; i++)
	if (read[i].getnumber() == readerid&&read[i].getnote() == 0)
	{
		read[i].delreader();
		cout << "��ɾ����" << endl;
	}
}
Reader *RDatabase::query(int readerid)               	//����Ų��ң����ص�ַ
{
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == readerid&&read[i].getnote() == 0)
			return &read[i];
	}
	return NULL;			
}
int RDatabase::addreader(int n, char *na)			//����¶���
{
	Reader *p = query(n);            			
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == n&&read[i].getnote() == 1)
		{
			cout << "�ö������������ѱ�ɾ����" << endl;
			read[i].addreader(n, na);
			cout << "�Ѹ�������Ϣ��" << endl;
			p = &read[i];
			return 1;
		}
	}
	if (p == NULL)
	{
		top++;
		read[top].addreader(n, na);	
		cout << "�ɹ���ӣ�" << endl;
		return 1;
	}
	if (p != NULL)
	{
		cout << "�ñ�����ж��ߣ�����������" << endl;
		return 1;
	}
	return 0;
}
void RDatabase::chreader(int n)			//����һ��������Ϣ
{
	char na[20];
	Reader *p = query(n);
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == n&&read[i].getnote() == 1)
		{
			cout << "�ñ�Ŷ������������ѱ�ɾ����" << endl;
			cout << "�������µ�������";
			cin >> na;
			read[i].setname(na);
			read[i].setnote();
			p = &read[i];
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	if (p == NULL)
	{
		cout << "�ö��߲����ڣ�" << endl;
		return;
	}
	cout << "�����µ�������";
	cin >> na;
	p->setname(na);
	cout << "�޸ĳɹ���" << endl;
}
void RDatabase::list()			//��ʾ���ж�����Ϣ
{
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnote() == 1)
		{
			cout << setw(5)<<read[i].getnumber()<<"   �ñ�Ŷ����ѱ�ɾ����" << endl;
		}
		if (read[i].getnote()==0)
			read[i].list();               			
	}
}
RDatabase::~RDatabase()			//��������
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
		cout << "����ά����" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cout << "��������Ҫִ�еĲ�����Ӧ��ţ�";
		cin >> choice;
		cout << "--------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "�����������߱�ţ�";
			cin >> readerid;
			cout << "������������������";
			cin >> readername;
			addreader(readerid, readername);                 
			break;
		case 2:cout << "����Ҫ���Ķ��ߵı�ţ�";		
			cin >> readerid;
			chreader(readerid);
			break;
		case 3:cout << "����Ҫɾ�����ߵı�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			clearone(readerid);
			break;
		case 4:cout << "����Ҫ���Ҷ��ߵı�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			r->list(); break;
		case 5:
			if (top == -1)
			{
				cout << "���޶�����Ϣ��" << endl;
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