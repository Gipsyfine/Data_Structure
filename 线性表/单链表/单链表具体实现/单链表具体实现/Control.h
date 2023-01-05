#pragma once
#include <iostream>
#include "LinkList.h"
using namespace std;

class Control
{
private:
	LinkList L;

public:

	//建立单链表
	void Create();

	//长度
	void Length();

	//取值
	void Get();

	//修改
	void Change();

	//插入
	void Insert();

	//删除
	void Delete();

	//查找
	void Find();

	//输出
	void show();

};