#pragma once
#include <iostream>
#include "LinkList.h"
using namespace std;

class Control
{
private:
	LinkList L;

public:

	//����������
	void Create();

	//����
	void Length();

	//ȡֵ
	void Get();

	//�޸�
	void Change();

	//����
	void Insert();

	//ɾ��
	void Delete();

	//����
	void Find();

	//���
	void show();

};