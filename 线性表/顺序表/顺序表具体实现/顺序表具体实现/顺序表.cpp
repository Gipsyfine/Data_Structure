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
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1������������
			p.Create();
			break;
		case 2://2������
			p.Length();
			break;
		case 3://3������
			p.Find();
			break;
		case 4://4������
			p.Insert();
			break;
		case 5://5��ɾ��
			p.Delete();
			break;
		case 6://6��ȡֵ
			p.Get();
			break;
		case 7://7������
			p.Turn();
			break;

		case 8://8�����
			p.Output();
			break;

		case 9://9�����
			p.Clear();
			break;

		case 10://10���ж��Ƿ�Ϊ��
			p.Is();
			break;

		case 0://0���˳�����
			cout << "�´μ���--Gipsyfine" << endl;
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
	cout << "*****  1������˳���    *****" << endl;
	cout << "*****  2����˳�����  *****" << endl;
	cout << "*****  3����������Ԫ��  *****" << endl;
	cout << "*****  4����������Ԫ��  *****" << endl;
	cout << "*****  5��ɾ������Ԫ��  *****" << endl;
	cout << "*****  6����ȡ����Ԫ��  *****" << endl;
	cout << "*****  7������˳���    *****" << endl;
	cout << "*****  8�����˳���    *****" << endl;
	cout << "*****  9�����˳���    *****" << endl;
	cout << "*****  10���ж��Ƿ�Ϊ�� *****" << endl;
	cout << "*****  0���˳�����      *****" << endl;
	cout << "*****************************" << endl;
}