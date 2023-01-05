#include <iostream>
#include <cstdlib>

using namespace std;

typedef int QElemType;

//链队列数据结点
typedef struct QNode
{
	QElemType data;
	QNode* next;
}QNode;

typedef struct
{
	QNode* front;//队头指针
	QNode* rear;//队尾指针
}LinkQNode;

class LinkQueue
{
private:
	LinkQNode q;

public:

	//初始化链队列
	LinkQueue()
	{
		q.front = q.rear = new QNode;
		q.front->next = NULL;
	}

	//销毁链队列
	~LinkQueue()
	{
		QNode* p = q.front->next;
		while (p)
		{
			q.front->next = p->next;
			delete p;
			p = q.front->next;
		}
		delete q.front;//删除最后一个结点
	}

	//入队
	void EnQueue(QElemType e)
	{
		QNode* s = new QNode;
		s->data = e;
		s->next = NULL;
		q.rear->next = s;
		q.rear = s;
	}

	//出队
	void DeQueue(QElemType& e)
	{
		if (q.front == q.rear)return;//队列为空，无法出队
		QNode* p = q.front->next;
		q.front->next = p->next;
		e = p->data;
		if (p == q.rear)q.rear = q.front;//若出队元素是尾指针所指元素，将尾指针修改，指向和头指针一样的地址
		delete p;
	}
	
	//获取队头元素
	int GetHead()
	{
		if (q.front == q.rear)
		{
			cout << "队列为空，无队头元素" << endl;
			exit(-1);
		}
		return q.front->next->data;
	}

	//判断是否为空
	int EmptyQueue()
	{
		if (q.front == q.rear)return 1;//队列为空，返回1
		else return 0;//队列非空。返回0
	}

	//求队列长度
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