#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;
#define initlistsize 100
#define increment 10

class SqList
{

private:
	ElemType* elem;//存放数组的首地址
	int listsize, length;//当前顺序表空间的大小和元素的数量

public:

	//初始化顺序表(构造函数)
	SqList();//创建一个长度为0，容量为initlistsize的空表

	//销毁顺序表(析构函数)
	~SqList();

	//创建n个元素的顺序表
	void CreateList(int n);

	//查找元素值
	int LocateList(ElemType x);

	//插入数据元素
	void InsertList(int i, ElemType e);//i是插入位置,e是数据元素

	//删除数据元素
	void DeleteList(int i, ElemType& e);//i是删除位置

	//顺序表的取值（根据位置i获取相应位置数据元素的内容--顺序表的这种机制称为随机存取）
	void GetElem(int i, ElemType& e);

	//清空顺序表
	void ClearList();

	//输出顺序表的长度
	int GetLength();

	//判断顺序表是否为空
	int IsEmpty();

	//倒置顺序表
	void TurnList();

	//合并顺序表
	void Mergelist(SqList LA, SqList LB, SqList& LC);

	//输出顺序表
	void PrintList();

};