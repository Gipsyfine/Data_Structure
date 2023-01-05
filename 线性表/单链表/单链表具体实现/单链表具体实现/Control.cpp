#include "Control.h"

//建立单链表
void Control::Create()
{
	int n;
	cout << "请输入单链表数据元素的个数：" << endl;
	cin >> n;
	cout << "请输入数据元素：" << endl;
	L.CreateList_T(n);

	//清屏
	system("pause");
	system("cls");
}

//长度
void Control::Length()
{
	cout << "单链表的长度为：" << L.ListLength() << endl;

	//清屏
	system("pause");
	system("cls");
}

//取值
void Control::Get()
{
	int i, e = 0;
	cout << "获取单链表的第i个数据元素(请输入数字i)：" << endl;
	cin >> i;

	int H = L.GetElem(i, e);
	if (H != 0)
	{
		cout << "获取成功！" << endl;
		cout << "该数据元素的值为：" << e << endl;
	}
	else
	{
		cout << "获取失败！不存在该结点。" << endl;
	}

	//清屏
	system("pause");
	system("cls");
}

//修改
void Control::Change()
{
	int i;
	cout << "修改单链表的第i个数据元素(请输入数字i)：" << endl;
	cin >> i;
	cout << "请输入新的数据元素：" << endl;
	L.ChangeElem(i);

	//清屏
	system("pause");
	system("cls");
}

//插入
void Control::Insert()
{
	int i, e;
	cout << "在单链表的第i个位置插入数据元素(请输入数字i)：" << endl;
	cin >> i;
	cout << "新结点的值为：" << endl;
	cin >> e;
	L.InsertList(i, e);

	//清屏
	system("pause");
	system("cls");
}

//删除
void Control::Delete()
{
	int i,e;
	cout << "删除单链表的第i个数据元素(请输入数字i)：" << endl;
	cin >> i;
	L.DeleteList(i, e);

	//清屏
	system("pause");
	system("cls");
}

//查找
void Control::Find()
{
	int e;
	cout << "请输入要查找的数据元素的值：" << endl;
	cin >> e;
	int Loc = L.LocateElem2(e);
	if (Loc)
	{
		cout << "查找成功！" << endl;
		cout << "位置序号为：" << Loc << endl;
	}
	else
	{
		cout << "未找到！" << endl;
	}

	//清屏
	system("pause");
	system("cls");
}

//输出
void Control::show()
{
	cout << "输出单链表的值：" << endl;
	L.Output();
	cout << endl;

	//清屏
	system("pause");
	system("cls");
}
