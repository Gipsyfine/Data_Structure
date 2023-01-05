#include <iostream>
#include <cstdlib>

using namespace std;

#define QueueSize 100//�����г���

typedef int QElemType;

class SqQueue
{
private:
	QElemType* base;//�洢�ռ��׵�ַ
	int front, rear;//frontΪ��ͷָ�룬rearΪ��βָ��(ʵ������һά�����±�)

public:

	//��ʼ���������ն���
	SqQueue()
	{
		base = new QElemType[QueueSize];
		front = rear = 0;
	}

	//���ٶ���
	~SqQueue()
	{
		delete[]base;
		front = rear = 0;
	}

	//����г���
	int QueueLength()
	{
		return((rear - front + QueueSize) % QueueSize);//�ǳ������ȥ����ƵP61
	}

	//��ӣ�ѭ�����У�
	void EnQueue(QElemType e)
	{
		if (front == (rear + 1) % QueueSize)return;//�����������޷����
		base[rear] = e;
		rear = (rear + 1) % QueueSize;
	}

	//���ӣ�ѭ�����У�
	void DeQueue(QElemType& e)
	{
		if (front == rear)return;//����Ϊ�գ��޷�����
		e = base[front];
		front = (front + 1) % QueueSize;
	}

	//��ȡ��ͷԪ��
	int GetHead()
	{
		if (front == rear)
		{
			cout << "���пգ��޶�ͷԪ��" << endl;
			exit(-1);
		}
		return base[front];
	}

	//�ж��Ƿ�Ϊ��
	int EmptyQueue()
	{
		if (front == rear)return 1;//����Ϊ�գ�����1
		else return 0;//���зǿգ�����0
	}

};
