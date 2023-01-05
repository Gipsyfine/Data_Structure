#include "Control.h"
#include <string>

//��������n������Ԫ�ص�˳���
void Control::Create()
{
	int n;
	cout << "������˳�������Ԫ�صĸ�����" << endl;
	cin >> n;
	cout << "����������Ԫ�أ�" << endl;
	L.CreateList(n);

	//����
	system("pause");
	system("cls");
}

//��������Ԫ��
void Control::Find()
{
	int n;
	cout << "������Ҫ���ҵ�����Ԫ�أ�" << endl;
	cin >> n;
	int i = L.LocateList(n);
	if (i != -1)
	{
		cout << "��Ԫ�ص�λ��Ϊ��" << i << endl;
	}
	else
	{
		cout << "δ�ҵ���" << endl;
	}

	//����
	system("pause");
	system("cls");
}

//��������Ԫ��
void Control::Insert()
{
	int n,k;
	cout << "������Ҫ�����λ�ú�����Ԫ�أ�" << endl;
	cin >> n >> k;
	L.InsertList(n, k);

	//����
	system("pause");
	system("cls");
}

//ɾ������Ԫ��
void Control::Delete()
{
	int i,e;
	cout << "������Ҫɾ��������Ԫ�ص�λ�ã�" << endl;
	cin >> i;
	L.DeleteList(i, e);
	cout << "ɾ��������Ԫ��Ϊ��" << e << endl;

	//����
	system("pause");
	system("cls");
}

//ȡֵ
void Control::Get()
{
	int i, e;
	cout << "������Ҫ��ȡ������Ԫ�ص�λ�ã�" << endl;
	cin >> i;
	L.GetElem(i, e);
	cout << "��" << i << "������Ԫ���ǣ�" << e << endl;

	//����
	system("pause");
	system("cls");
}

//���
void Control::Clear()
{
	cout << "����ȷ�����˳�����(Y/N)" << endl;
	string n;
	cin >> n;
	if (n == "Y")
	{
		L.ClearList();
		cout << "�����" << endl;
	}

	//����
	system("pause");
	system("cls");

}

//�ж�˳����Ƿ�Ϊ��
void Control::Is()
{
	int i = L.IsEmpty();
	if (i == 1)
	{
		cout << "˳���Ϊ��" << endl;
	}
	else
	{
		cout << "˳���Ϊ��" << endl;
	}

	//����
	system("pause");
	system("cls");
}

//����
void Control::Length()
{
	cout << "˳���ĳ���Ϊ��" << L.GetLength() << endl;

	//����
	system("pause");
	system("cls");
}

//����
void Control::Turn()
{
	L.TurnList();
	cout << "������ɣ�" << endl;

	//����
	system("pause");
	system("cls");
}

//�������
void Control::Output()
{
	L.PrintList();

	//����
	system("pause");
	system("cls");
}
