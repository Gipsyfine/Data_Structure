#include <iostream>
#include "SqList.h"
#include "Control.h"

void showMenu();

int main()
{
	Control p;
	int select = 0;

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
		case 3://3、查找
			p.Find();
			break;
		case 4://4、插入
			p.Insert();
			break;
		case 5://5、删除
			p.Delete();
			break;
		case 6://6、取值
			p.Get();
			break;
		case 7://7、倒置
			p.Turn();
			break;

		case 8://8、输出
			p.Output();
			break;

		case 9://9、清空
			p.Clear();
			break;

		case 10://10、判断是否为空
			p.Is();
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
	
}

void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****  1、建立顺序表    *****" << endl;
	cout << "*****  2、求顺序表长度  *****" << endl;
	cout << "*****  3、查找数据元素  *****" << endl;
	cout << "*****  4、插入数据元素  *****" << endl;
	cout << "*****  5、删除数据元素  *****" << endl;
	cout << "*****  6、获取数据元素  *****" << endl;
	cout << "*****  7、倒置顺序表    *****" << endl;
	cout << "*****  8、输出顺序表    *****" << endl;
	cout << "*****  9、清空顺序表    *****" << endl;
	cout << "*****  10、判断是否为空 *****" << endl;
	cout << "*****  0、退出程序      *****" << endl;
	cout << "*****************************" << endl;
}