#pragma once
#include <iostream>
#include "SqList.h"
using namespace std;

class Control
{
private:
	SqList L;

public:

	//��������n������Ԫ�ص�˳���
	void Create();

	//��������Ԫ��
	void Find();

	//��������Ԫ��
	void Insert();

	//ɾ������Ԫ��
	void Delete();

	//ȡֵ
	void Get();

	//���
	void Clear();

	//�ж�˳����Ƿ�Ϊ��
	void Is();

	//����
	void Length();

	//����
	void Turn();

	//�������
	void Output();

};