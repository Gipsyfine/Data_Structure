#include <iostream>
#include "LinkList.h"
#include "Control.h"

void showMenu();

int main()
{
	Control p;

	int select = 0;//创建用户选择输入的变量

	while (true)
	{

		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1、建立单链表
			p.Create();
			break;
		case 2://2、长度
			p.Length();
			break;
		case 3://3、取值
			p.Get();
			break;
		case 4://4、修改
			p.Change();
			break;
		case 5://5、插入
			p.Insert();
			break;
		case 6://6、查找
			p.Find();
			break;
		case 7://7、删除
			p.Delete();
			break;

		case 8://8、输出
			p.show();
			break;

		case 0://0、退出程序
			cout << "下次见！--Gipsyfine" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;

		}
	}

	system("pause");

	return 0;
}

void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****  1、建立单链表    *****" << endl;
	cout << "*****  2、求单链表长度  *****" << endl;
	cout << "*****  3、获取数据元素  *****" << endl;
	cout << "*****  4、修改数据元素  *****" << endl;
	cout << "*****  5、插入数据元素  *****" << endl;
	cout << "*****  6、查找数据元素  *****" << endl;
	cout << "*****  7、删除数据元素  *****" << endl;
	cout << "*****  8、输出单链表    *****" << endl;
	cout << "*****  0、退出程序      *****" << endl;
	cout << "*****************************" << endl;
}
