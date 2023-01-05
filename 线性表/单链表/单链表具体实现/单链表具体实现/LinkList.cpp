#include "LinkList.h"

//������������캯����
LinkList::LinkList()
{
	head = new LNode;
	head->next = NULL;
}

//������������������
LinkList::~LinkList()
{
	LNode* p = head;
	while (p)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

//��������n������Ԫ�صĵ�����ͷ�巨--Ԫ�ز���������ͷ����Ҳ��ǰ�巨
void LinkList::CreateList_H(int n)
{
	LNode* s;
	for (int i = n;i > 0;i--)
	{
		s = new LNode;//�����½��
		cin >> s->data;//��λ������Ԫ��ֵ����Ϊ��ͷ�巨
		s->next = head->next;//���뵽��ͷ
		head->next = s;
	}
}

//��������n������Ԫ�صĵ�����β�巨--Ԫ�ز���������β����Ҳ�к�巨
void LinkList::CreateList_T(int n)
{
	LNode* r = head;//βָ��rָ��ͷ���
	LNode* s;
	for (int i = 0;i < n;i++)
	{
		s = new LNode;//�����½��
		cin >> s->data;//��λ������Ԫ��ֵ����Ϊ��β�巨
		s->next = NULL;//β���ָ����Ϊ��
		r->next = s;//���뵽��β
		r = s;//rָ���µ�β���
	}
}

//������ĳ���
int LinkList::ListLength()
{
	LNode* p = head->next;//pָ���һ�����
	int count = 0;
	while (p)//����������ͳ�ƽ����
	{
		count++;
		p = p->next;
	}
	return count;//���ؽ�������
}

//��ȡ������ĵ�i������Ԫ�أ�������������ֵ��e
int LinkList::GetElem(int i, ElemType& e)
{
	int j = 1;
	LNode* p = head->next;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return 0;//�����ڵ�i����㣬���� 0
	}
	else
	{
		e = p->data;
		return 1;//���ڵ�i����㣬���� 1
	}
}

//�޸ĵ�����ĵ�i������Ԫ��
void LinkList::ChangeElem(int i)
{
	int count = 1;
	LNode* p = head->next;
	while (p != NULL)//�ж��Ƿ�Ϊ������
	{
		if (count == i)
		{
			cin >> p->data;
		}
		p = p->next;
		count++;
	}
}

//�ڵ�����ĵ�i��λ�ò�������Ԫ��e
void LinkList::InsertList(int i, ElemType e)
{
	LNode* p = head;//��ʼ������ָ��
	LNode* s;
	int j = 0;//��ʼ��������
	while (p && j < i - 1)//���ҵ�i-1����㣬����pָ��ý��
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)//����λ�ò������쳣����
	{
		return;
	}
	else//���ҳɹ�������ֵΪe���½��s������s����ָ��p��ָ���ĺ���
	{
		s = new LNode;//�����½��
		s->data = e;
		s->next = p->next;//�����½��
		p->next = s;
	}
}

//ɾ�����е�i��λ���ϵ�����Ԫ�أ���������Ԫ�ص�ֵ��e
void LinkList::DeleteList(int i, ElemType& e)
{
	LNode* p = head;//��ʼ������ָ��
	int j = 0;//��ʼ��������
	while (p->next && j < i - 1)//���ҵ�i-1����㣬����pָ��ý��
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)//ɾ��λ�ò������쳣����
	{
		return;
	}
	else
	{
		LNode* q = p->next;
		e = q->data;//�����ɾ����������Ԫ��
		p->next = q->next;//ɾ�����
		delete q;//�ͷſռ�
	}
}

//���ҵ�������ֵΪe������Ԫ�أ����ظ�����Ԫ�صĵ�ַ��
LNode* LinkList::LocateElem(ElemType e)
{
	LNode* p = head->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;//�ҵ����򷵻�������ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL
}

//���ҵ�������ֵΪe������Ԫ�أ����ظ�����Ԫ�ص�λ����ţ�
int LinkList::LocateElem2(ElemType e)
{
	LNode* p = head->next;
	int count = 1;//��ʼ��������
	while (p && p->data != e)
	{
		p = p->next;
		count++;
	}
	if (p)//�ҵ����򷵻�������ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0
	{
		return count;
	}
	else
	{
		return 0;
	}

}

//�������������Ԫ��
void LinkList::Output()
{
	LNode* p = head->next;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}

