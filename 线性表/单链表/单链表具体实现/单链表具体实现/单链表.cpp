#include <iostream>
#include "LinkList.h"
#include "Control.h"

void showMenu();

int main()
{
	Control p;

	int select = 0;//�����û�ѡ������ı���

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
		case 3://3��ȡֵ
			p.Get();
			break;
		case 4://4���޸�
			p.Change();
			break;
		case 5://5������
			p.Insert();
			break;
		case 6://6������
			p.Find();
			break;
		case 7://7��ɾ��
			p.Delete();
			break;

		case 8://8�����
			p.show();
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

	system("pause");

	return 0;
}

void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****  1������������    *****" << endl;
	cout << "*****  2����������  *****" << endl;
	cout << "*****  3����ȡ����Ԫ��  *****" << endl;
	cout << "*****  4���޸�����Ԫ��  *****" << endl;
	cout << "*****  5����������Ԫ��  *****" << endl;
	cout << "*****  6����������Ԫ��  *****" << endl;
	cout << "*****  7��ɾ������Ԫ��  *****" << endl;
	cout << "*****  8�����������    *****" << endl;
	cout << "*****  0���˳�����      *****" << endl;
	cout << "*****************************" << endl;
}
