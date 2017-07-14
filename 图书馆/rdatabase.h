#ifndef _rdatabase_h_
#define _rdatabase_h_
#include "reader.h"
#include <iostream>
using namespace std;
const int Maxr = 100;		//��������
class RDatabase				//���߿�
{
private:
	int top;				//���߼�¼ָ��
	Reader read[Maxr];		//���߼�¼
public:
	RDatabase();			//���캯����ʼ�������ļ�
	void clear();			//ɾ�����ж�����Ϣ
	void clearone(int readerid);			//ɾ��һ��������Ϣ
	int addreader(int n, char *na);			//��Ӷ��߼�¼����ȷ�����Ƿ��Ѿ�����
	Reader *query(int readerid);			//����Ų���
	void chreader(int n);         //����һ��������Ϣ
	void list();			//������ж�����Ϣ
	void readerdata();			//���߿�ά��
	~RDatabase();			//����������д�ļ�
};
#endif