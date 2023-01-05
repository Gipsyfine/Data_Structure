#pragma once
#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
} LNode;

class LinkList
{
private:
	LNode* head;

public:

	//������������캯����
	LinkList();

	//������������������
	~LinkList();

	//��������n������Ԫ�صĵ�����ͷ�巨--Ԫ�ز���������ͷ����Ҳ��ǰ�巨
	void CreateList_H(int n);

	//��������n������Ԫ�صĵ�����β�巨--Ԫ�ز���������β����Ҳ�к�巨
	void CreateList_T(int n);

	//������ĳ���
	int ListLength();

	//��ȡ������ĵ�i������Ԫ�أ�������������ֵ��e
	int GetElem(int i, ElemType& e);

	//�޸ĵ�����ĵ�i������Ԫ��
	void ChangeElem(int i);

	//�ڵ�����ĵ�i��λ�ò�������Ԫ��e
	void InsertList(int i, ElemType e);

	//ɾ�����е�i��λ���ϵ�����Ԫ�أ���������Ԫ�ص�ֵ��e
	void DeleteList(int i, ElemType& e);

	//���ҵ�������ֵΪe������Ԫ�أ����ظ�����Ԫ�صĵ�ַ��
	LNode* LocateElem(ElemType e);

	//���ҵ�������ֵΪe������Ԫ�أ����ظ�����Ԫ�ص�λ����ţ�
	int LocateElem2(ElemType e);

	//�������������Ԫ��
	void Output();

};