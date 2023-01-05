#include "Control.h"
#include <string>

//建立具有n个数据元素的顺序表
void Control::Create()
{
	int n;
	cout << "请输入顺序表数据元素的个数：" << endl;
	cin >> n;
	cout << "请输入数据元素：" << endl;
	L.CreateList(n);

	//清屏
	system("pause");
	system("cls");
}

//查找数据元素
void Control::Find()
{
	int n;
	cout << "请输入要查找的数据元素：" << endl;
	cin >> n;
	int i = L.LocateList(n);
	if (i != -1)
	{
		cout << "该元素的位置为：" << i << endl;
	}
	else
	{
		cout << "未找到！" << endl;
	}

	//清屏
	system("pause");
	system("cls");
}

//插入数据元素
void Control::Insert()
{
	int n,k;
	cout << "请输入要插入的位置和数据元素：" << endl;
	cin >> n >> k;
	L.InsertList(n, k);

	//清屏
	system("pause");
	system("cls");
}

//删除数据元素
void Control::Delete()
{
	int i,e;
	cout << "请输入要删除的数据元素的位置：" << endl;
	cin >> i;
	L.DeleteList(i, e);
	cout << "删除的数据元素为：" << e << endl;

	//清屏
	system("pause");
	system("cls");
}

//取值
void Control::Get()
{
	int i, e;
	cout << "请输入要获取的数据元素的位置：" << endl;
	cin >> i;
	L.GetElem(i, e);
	cout << "第" << i << "个数据元素是：" << e << endl;

	//清屏
	system("pause");
	system("cls");
}

//清空
void Control::Clear()
{
	cout << "请问确定清空顺序表吗？(Y/N)" << endl;
	string n;
	cin >> n;
	if (n == "Y")
	{
		L.ClearList();
		cout << "已清空" << endl;
	}

	//清屏
	system("pause");
	system("cls");

}

//判断顺序表是否为空
void Control::Is()
{
	int i = L.IsEmpty();
	if (i == 1)
	{
		cout << "顺序表为空" << endl;
	}
	else
	{
		cout << "顺序表不为空" << endl;
	}

	//清屏
	system("pause");
	system("cls");
}

//长度
void Control::Length()
{
	cout << "顺序表的长度为：" << L.GetLength() << endl;

	//清屏
	system("pause");
	system("cls");
}

//倒置
void Control::Turn()
{
	L.TurnList();
	cout << "倒置完成！" << endl;

	//清屏
	system("pause");
	system("cls");
}

//遍历输出
void Control::Output()
{
	L.PrintList();

	//清屏
	system("pause");
	system("cls");
}
