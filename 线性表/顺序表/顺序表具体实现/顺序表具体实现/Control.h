#pragma once
#include <iostream>
#include "SqList.h"
using namespace std;

class Control
{
private:
	SqList L;

public:

	//建立具有n个数据元素的顺序表
	void Create();

	//查找数据元素
	void Find();

	//插入数据元素
	void Insert();

	//删除数据元素
	void Delete();

	//取值
	void Get();

	//清空
	void Clear();

	//判断顺序表是否为空
	void Is();

	//长度
	void Length();

	//倒置
	void Turn();

	//遍历输出
	void Output();

};