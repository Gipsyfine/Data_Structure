#include "Control.h"

//����������
void Control::Create()
{
	int n;
	cout << "�����뵥��������Ԫ�صĸ�����" << endl;
	cin >> n;
	cout << "����������Ԫ�أ�" << endl;
	L.CreateList_T(n);

	//����
	system("pause");
	system("cls");
}

//����
void Control::Length()
{
	cout << "������ĳ���Ϊ��" << L.ListLength() << endl;

	//����
	system("pause");
	system("cls");
}

//ȡֵ
void Control::Get()
{
	int i, e = 0;
	cout << "��ȡ������ĵ�i������Ԫ��(����������i)��" << endl;
	cin >> i;

	int H = L.GetElem(i, e);
	if (H != 0)
	{
		cout << "��ȡ�ɹ���" << endl;
		cout << "������Ԫ�ص�ֵΪ��" << e << endl;
	}
	else
	{
		cout << "��ȡʧ�ܣ������ڸý�㡣" << endl;
	}

	//����
	system("pause");
	system("cls");
}

//�޸�
void Control::Change()
{
	int i;
	cout << "�޸ĵ�����ĵ�i������Ԫ��(����������i)��" << endl;
	cin >> i;
	cout << "�������µ�����Ԫ�أ�" << endl;
	L.ChangeElem(i);

	//����
	system("pause");
	system("cls");
}

//����
void Control::Insert()
{
	int i, e;
	cout << "�ڵ�����ĵ�i��λ�ò�������Ԫ��(����������i)��" << endl;
	cin >> i;
	cout << "�½���ֵΪ��" << endl;
	cin >> e;
	L.InsertList(i, e);

	//����
	system("pause");
	system("cls");
}

//ɾ��
void Control::Delete()
{
	int i,e;
	cout << "ɾ��������ĵ�i������Ԫ��(����������i)��" << endl;
	cin >> i;
	L.DeleteList(i, e);

	//����
	system("pause");
	system("cls");
}

//����
void Control::Find()
{
	int e;
	cout << "������Ҫ���ҵ�����Ԫ�ص�ֵ��" << endl;
	cin >> e;
	int Loc = L.LocateElem2(e);
	if (Loc)
	{
		cout << "���ҳɹ���" << endl;
		cout << "λ�����Ϊ��" << Loc << endl;
	}
	else
	{
		cout << "δ�ҵ���" << endl;
	}

	//����
	system("pause");
	system("cls");
}

//���
void Control::show()
{
	cout << "����������ֵ��" << endl;
	L.Output();
	cout << endl;

	//����
	system("pause");
	system("cls");
}
