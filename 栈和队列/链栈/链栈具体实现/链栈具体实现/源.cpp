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
	LinkNode* top;//栈顶指针即链栈的头指针

public:

	//置空链栈
	LinkStack()
	{
		top = new LinkNode;
		top->next = NULL;
	}

	//销毁栈
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
		delete p;//删除最后一个结点
	}

	//判断链栈是否为空
	int EmptyStack()
	{
		if (top->next == NULL)return 1;//栈为空，返回1
		else return 0;//栈为非空，返回0
	}

	//入栈
	void Push(SElemType e)
	{
		LinkNode* s = new LinkNode;//分配空间
		s->data = e;//将新结点的数据域置为e
		s->next = top->next;
		top->next = s;//修改栈顶指针
	}

	//出栈
	void Pop(SElemType& e)
	{
		if (top->next == NULL)return;//栈为空，出栈操作不合法
		LinkNode* p = top->next;//p指向存放第一个元素的结点
		e = p->data;
		top->next = p->next;
		delete p;//删除存放第一个元素的结点
	}

	//取栈顶元素
	SElemType GetTop()
	{
		if (top->next == NULL)
		{
			cout << "栈空，无法获取元素" << endl;
			exit(-1);
		}
		return top->next->data;
	}

};