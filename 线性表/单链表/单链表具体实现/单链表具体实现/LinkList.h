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

	//构造空链表（构造函数）
	LinkList();

	//销毁链表（析构函数）
	~LinkList();

	//建立具有n个数据元素的单链表：头插法--元素插入在链表头部，也叫前插法
	void CreateList_H(int n);

	//建立具有n个数据元素的单链表：尾插法--元素插入在链表尾部，也叫后插法
	void CreateList_T(int n);

	//求单链表的长度
	int ListLength();

	//获取单链表的第i个数据元素，并将其数据域赋值给e
	int GetElem(int i, ElemType& e);

	//修改单链表的第i个数据元素
	void ChangeElem(int i);

	//在单链表的第i个位置插入数据元素e
	void InsertList(int i, ElemType e);

	//删除表中第i个位置上的数据元素，保存数据元素的值到e
	void DeleteList(int i, ElemType& e);

	//查找单链表中值为e的数据元素（返回该数据元素的地址）
	LNode* LocateElem(ElemType e);

	//查找单链表中值为e的数据元素（返回该数据元素的位置序号）
	int LocateElem2(ElemType e);

	//输出单链表数据元素
	void Output();

};