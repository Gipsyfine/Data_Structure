#include <iostream>
#include <cstdlib>

using namespace std;

typedef int QElemType;

//���������ݽ��
typedef struct QNode
{
	QElemType data;
	QNode* next;
}QNode;

typedef struct
{
	QNode* front;//��ͷָ��
	QNode* rear;//��βָ��
}LinkQNode;

class LinkQueue
{
private:
	LinkQNode q;

public:

	//��ʼ��������
	LinkQueue()
	{
		q.front = q.rear = new QNode;
		q.front->next = NULL;
	}

	//����������
	~LinkQueue()
	{
		QNode* p = q.front->next;
		while (p)
		{
			q.front->next = p->next;
			delete p;
			p = q.front->next;
		}
		delete q.front;//ɾ�����һ�����
	}

	//���
	void EnQueue(QElemType e)
	{
		QNode* s = new QNode;
		s->data = e;
		s->next = NULL;
		q.rear->next = s;
		q.rear = s;
	}

	//����
	void DeQueue(QElemType& e)
	{
		if (q.front == q.rear)return;//����Ϊ�գ��޷�����
		QNode* p = q.front->next;
		q.front->next = p->next;
		e = p->data;
		if (p == q.rear)q.rear = q.front;//������Ԫ����βָ����ָԪ�أ���βָ���޸ģ�ָ���ͷָ��һ���ĵ�ַ
		delete p;
	}
	
	//��ȡ��ͷԪ��
	int GetHead()
	{
		if (q.front == q.rear)
		{
			cout << "����Ϊ�գ��޶�ͷԪ��" << endl;
			exit(-1);
		}
		return q.front->next->data;
	}

	//�ж��Ƿ�Ϊ��
	int EmptyQueue()
	{
		if (q.front == q.rear)return 1;//����Ϊ�գ�����1
		else return 0;//���зǿա�����0
	}

	//����г���
	int QueueLength()
	{
		QNode* p = q.front->next;
		int count = 0;
		while (p)
		{
			count++;
			p = p->next;
		}
		return count;
	}

};