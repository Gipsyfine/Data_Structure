#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;
#define initlistsize 100
#define increment 10

class SqList
{

private:
	ElemType* elem;//���������׵�ַ
	int listsize, length;//��ǰ˳���ռ�Ĵ�С��Ԫ�ص�����

public:

	//��ʼ��˳���(���캯��)
	SqList();//����һ������Ϊ0������Ϊinitlistsize�Ŀձ�

	//����˳���(��������)
	~SqList();

	//����n��Ԫ�ص�˳���
	void CreateList(int n);

	//����Ԫ��ֵ
	int LocateList(ElemType x);

	//��������Ԫ��
	void InsertList(int i, ElemType e);//i�ǲ���λ��,e������Ԫ��

	//ɾ������Ԫ��
	void DeleteList(int i, ElemType& e);//i��ɾ��λ��

	//˳����ȡֵ������λ��i��ȡ��Ӧλ������Ԫ�ص�����--˳�������ֻ��Ƴ�Ϊ�����ȡ��
	void GetElem(int i, ElemType& e);

	//���˳���
	void ClearList();

	//���˳���ĳ���
	int GetLength();

	//�ж�˳����Ƿ�Ϊ��
	int IsEmpty();

	//����˳���
	void TurnList();

	//�ϲ�˳���
	void Mergelist(SqList LA, SqList LB, SqList& LC);

	//���˳���
	void PrintList();

};