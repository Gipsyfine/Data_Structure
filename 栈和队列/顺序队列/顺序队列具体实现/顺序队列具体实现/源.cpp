#include <iostream>
#include <cstdlib>

using namespace std;

#define QueueSize 100//最大队列长度

typedef int QElemType;

class SqQueue
{
private:
	QElemType* base;//存储空间首地址
	int front, rear;//front为队头指针，rear为队尾指针(实际上是一维数组下标)

public:

	//初始化，建立空队列
	SqQueue()
	{
		base = new QElemType[QueueSize];
		front = rear = 0;
	}

	//销毁队列
	~SqQueue()
	{
		delete[]base;
		front = rear = 0;
	}

	//求队列长度
	int QueueLength()
	{
		return((rear - front + QueueSize) % QueueSize);//非常妙，不懂去看视频P61
	}

	//入队（循环队列）
	void EnQueue(QElemType e)
	{
		if (front == (rear + 1) % QueueSize)return;//队列已满，无法入队
		base[rear] = e;
		rear = (rear + 1) % QueueSize;
	}

	//出队（循环队列）
	void DeQueue(QElemType& e)
	{
		if (front == rear)return;//队列为空，无法出队
		e = base[front];
		front = (front + 1) % QueueSize;
	}

	//获取队头元素
	int GetHead()
	{
		if (front == rear)
		{
			cout << "队列空，无队头元素" << endl;
			exit(-1);
		}
		return base[front];
	}

	//判断是否为空
	int EmptyQueue()
	{
		if (front == rear)return 1;//队列为空，返回1
		else return 0;//队列非空，返回0
	}

};
