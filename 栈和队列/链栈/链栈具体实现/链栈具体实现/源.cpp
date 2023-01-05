#include <iostream>

using namespace std;

typedef int SElemType;
typedef struct LinkNode
{
	SElemType data;
	LinkNode* next;
}LinkNode;

class LinkStack
{

private:
	LinkNode* top;//ջ��ָ�뼴��ջ��ͷָ��

public:

	//�ÿ���ջ
	LinkStack()
	{
		top = new LinkNode;
		top->next = NULL;
	}

	//����ջ
	~LinkStack()
	{
		LinkNode* p = top;
		LinkNode* q = top->next;
		while (q)
		{
			delete p;
			p = q;
			q = q->next;
		}
		delete p;//ɾ�����һ�����
	}

	//�ж���ջ�Ƿ�Ϊ��
	int EmptyStack()
	{
		if (top->next == NULL)return 1;//ջΪ�գ�����1
		else return 0;//ջΪ�ǿգ�����0
	}

	//��ջ
	void Push(SElemType e)
	{
		LinkNode* s = new LinkNode;//����ռ�
		s->data = e;//���½�����������Ϊe
		s->next = top->next;
		top->next = s;//�޸�ջ��ָ��
	}

	//��ջ
	void Pop(SElemType& e)
	{
		if (top->next == NULL)return;//ջΪ�գ���ջ�������Ϸ�
		LinkNode* p = top->next;//pָ���ŵ�һ��Ԫ�صĽ��
		e = p->data;
		top->next = p->next;
		delete p;//ɾ����ŵ�һ��Ԫ�صĽ��
	}

	//ȡջ��Ԫ��
	SElemType GetTop()
	{
		if (top->next == NULL)
		{
			cout << "ջ�գ��޷���ȡԪ��" << endl;
			exit(-1);
		}
		return top->next->data;
	}

};