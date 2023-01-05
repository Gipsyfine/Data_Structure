//#include <iostream>
//using namespace std;
//
////����������
////   ʵ�ִ�ͷ���ĵ�����Ľ������󳤶ȣ�ȡԪ�ء��޸�Ԫ�ء����롢ɾ����
////   ������Ļ���������
//
//typedef int ElemType;
//
//typedef struct LNode
//{
//	ElemType data;
//	struct LNode* next;
//} LNode;
//
//class LinkList
//{
//private:
//	LNode* head;
//
//public:
//
//	//������������캯����
//	LinkList()
//	{
//		head = new LNode;
//		head->next = NULL;
//	}
//
//	//������������������
//	~LinkList()
//	{
//		LNode* p = head;
//		while (p)
//		{
//			head = head->next;
//			delete p;
//			p = head;
//		}
//	}
//
//	//��������n������Ԫ�صĵ�����ͷ�巨--Ԫ�ز���������ͷ����Ҳ��ǰ�巨
//	void CreateList_H(int n)
//	{
//		LNode* s;
//		for (int i = n;i > 0;i--)
//		{
//			s = new LNode;//�����½��
//			cin >> s->data;//��λ������Ԫ��ֵ����Ϊ��ͷ�巨
//			s->next = head->next;//���뵽��ͷ
//			head->next = s;
//		}
//	}
//
//	//��������n������Ԫ�صĵ�����β�巨--Ԫ�ز���������β����Ҳ�к�巨
//	void CreateList_T(int n)
//	{
//		LNode* r = head;//βָ��rָ��ͷ���
//		LNode* s;
//		for (int i = 0;i < n;i++)
//		{
//			s = new LNode;//�����½��
//			cin >> s->data;//��λ������Ԫ��ֵ����Ϊ��β�巨
//			s->next = NULL;//β���ָ����Ϊ��
//			r->next = s;//���뵽��β
//			r = s;//rָ���µ�β���
//		}
//	}
//
//	//������ĳ���
//	int ListLength()
//	{
//		LNode* p = head->next;//pָ���һ�����
//		int count = 0;
//		while (p)//����������ͳ�ƽ����
//		{
//			count++;
//			p = p->next;
//		}
//		return count;//���ؽ�������
//	}
//
//	//��ȡ������ĵ�i������Ԫ�أ�������������ֵ��e
//	int GetElem(int i, ElemType& e)
//	{
//		int j = 1;
//		LNode* p = head->next;
//		while (p && j < i)
//		{
//			p = p->next;
//			j++;
//		}
//		if (!p || j > i)
//		{
//			return 0;//�����ڵ�i����㣬���� 0
//		}
//		else
//		{
//			e = p->data;
//			return 1;//���ڵ�i����㣬���� 1
//		}
//	}
//
//	//�޸ĵ�����ĵ�i������Ԫ��
//	void ChangeElem(int i)
//	{
//		int count = 1;
//		LNode* p = head->next;
//		while (p != NULL)//�ж��Ƿ�Ϊ������
//		{
//			if (count == i)
//			{
//				cin >> p->data;
//			}
//			p = p->next;
//			count++;
//		}
//	}
//
//	//�ڵ�����ĵ�i��λ�ò�������Ԫ��e
//	void InsertList(int i, ElemType e)
//	{
//		LNode* p = head;//��ʼ������ָ��
//		LNode* s;
//		int j = 0;//��ʼ��������
//		while (p && j < i - 1)//���ҵ�i-1����㣬����pָ��ý��
//		{
//			p = p->next;
//			j++;
//		}
//
//		if (!p || j > i - 1)//����λ�ò������쳣����
//		{
//			return;
//		}
//		else//���ҳɹ�������ֵΪe���½��s������s����ָ��p��ָ���ĺ���
//		{
//			s = new LNode;//�����½��
//			s->data = e;
//			s->next = p->next;//�����½��
//			p->next = s;
//		}
//	}
//
//	//ɾ�����е�i��λ���ϵ�����Ԫ�أ���������Ԫ�ص�ֵ��e
//	void DeleteList(int i, ElemType& e)
//	{
//		LNode* p = head;//��ʼ������ָ��
//		int j = 0;//��ʼ��������
//		while (p->next && j < i - 1)//���ҵ�i-1����㣬����pָ��ý��
//		{
//			p = p->next;
//			j++;
//		}
//		if (!p->next || j > i - 1)//ɾ��λ�ò������쳣����
//		{
//			return;
//		}
//		else
//		{
//			LNode* q = p->next;
//			e = q->data;//�����ɾ����������Ԫ��
//			p->next = q->next;//ɾ�����
//			delete q;//�ͷſռ�
//		}
//	}
//
//	//���ҵ�������ֵΪe������Ԫ�أ����ظ�����Ԫ�صĵ�ַ��
//	LNode* LocateElem(ElemType e)
//	{
//		LNode* p = head->next;
//		while (p && p->data != e)
//		{
//			p = p->next;
//		}
//		return p;//�ҵ����򷵻�������ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL
//	}
//
//	//���ҵ�������ֵΪe������Ԫ�أ����ظ�����Ԫ�ص�λ����ţ�
//	int LocateElem2(ElemType e)
//	{
//		LNode* p = head->next;
//		int count = 1;//��ʼ��������
//		while (p && p->data != e)
//		{
//			p = p->next;
//			count++;
//		}
//		if (p)//�ҵ����򷵻�������ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0
//		{
//			return count;
//		}
//		else
//		{
//			return 0;
//		}
//		
//	}
//
//	//�������������Ԫ��
//	void Output()
//	{
//		LNode* p = head->next;
//		while (p)
//		{
//			cout << p->data << "\t";
//			p = p->next;
//		}
//	}
//
//
//};
//
//void showMenu()
//{
//	cout << "***************************" << endl;
//	cout << "*****  1������������   *****" << endl;
//	cout << "*****  2����������  *****" << endl;
//	cout << "*****  3����ȡ����Ԫ��  *****" << endl;
//	cout << "*****  4���޸�����Ԫ��  *****" << endl;
//	cout << "*****  5����������Ԫ��  *****" << endl;
//	cout << "*****  6����������Ԫ��  *****" << endl;
//	cout << "*****  7��ɾ������Ԫ��  *****" << endl;
//	cout << "*****  0�����������   *****" << endl;
//	cout << "***************************" << endl;
//}
//
//
//int main()
//{
//	LinkList L;
//	//��������n������Ԫ�صĵ�����
//	int n;
//	cout << "�����뵥��������Ԫ�صĸ�����" << endl;
//	cin >> n;
//	cout << "����������Ԫ�أ�" << endl;
//	L.CreateList_T(n);
//
//	//������ĳ���
//	cout << "������ĳ���Ϊ��" << endl;
//	cout << L.ListLength() << endl;
//
//	//��ȡ������ĵ�i������Ԫ�أ�������������ֵ��e
//	int i,e=0;
//	cout << "��ȡ������ĵ�i������Ԫ��(����������i)��" << endl;
//	cin >> i;
//	
//	int H = L.GetElem(i, e);
//	if (H != 0)
//	{
//		cout << "��ȡ�ɹ���" << endl;
//		cout << "������Ԫ�ص�ֵΪ��" << e << endl;
//	}
//	else
//	{
//		cout << "��ȡʧ�ܣ������ڸý�㡣" << endl;
//	}
//
//	//�޸ĵ�����ĵ�i������Ԫ��
//	cout << "�޸ĵ�����ĵ�i������Ԫ��(����������i)��" << endl;
//	cin >> i;
//
//	L.ChangeElem(i);
//
//	//�ڵ�����ĵ�i��λ�ò�������Ԫ��e
//	cout << "�ڵ�����ĵ�i��λ�ò�������Ԫ��(����������i)��" << endl;
//	cin >> i;
//	cout << "�½���ֵΪ��" << endl;
//	cin >> e;
//	L.InsertList(i, e);
//
//   //ɾ�����е�i��λ���ϵ�����Ԫ�أ���������Ԫ�ص�ֵ��e
//	cout << "ɾ��������ĵ�i������Ԫ��(����������i)��" << endl;
//	cin >> i;
//	L.DeleteList(i, e);
//
//	//���ҵ�������ֵΪe������Ԫ�أ����ظ�����Ԫ�ص�λ����ţ�
//	cout << "������Ҫ���ҵ�����Ԫ�ص�ֵ��" << endl;
//	cin >> e;
//	int Loc = L.LocateElem2(e);
//	if (Loc)
//	{
//		cout << "���ҳɹ���" << endl;
//		cout << "λ�����Ϊ��" << Loc << endl;
//	}
//	else
//	{
//		cout << "δ�ҵ���" << endl;
//	}
//
//	//�������������Ԫ��
//	
//	L.Output();
//
//	system("pause");
//
//	return 0;
//}