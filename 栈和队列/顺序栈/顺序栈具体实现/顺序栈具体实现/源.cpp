#include <iostream>
#include <cstdlib>

using namespace std;

#define InitStackSize 100
#define StackIncrement 10

typedef int SElemType;

class SqStack
{

private:
	SElemType* base, * top;//base为栈底指针，top为栈顶指针
	int stacksize;//栈容量

public:

	//初始化，建立空栈
	SqStack()
	{
		base = top = new SElemType[InitStackSize];
		stacksize = InitStackSize;
	}

	//销毁栈
	~SqStack()
	{
		delete[]base;
		stacksize = 0;
	}

	//判断栈是否为空栈
	int EmptyStack() 
	{
		if (top == base)return 1;//栈为空，返回1
		else return 0;//栈为非空，返回0
	}

	//求顺序栈长度
	int StackLength()
	{
		return top - base;
	}

	//清空顺序栈
	void ClearStack()
	{
		if (base)top = base;
	}

	//销毁顺序栈
	void DestroyStack()
	{
		if (base)
		{
			delete base;
			stacksize = 0;
			base = top = NULL;//不赋值NULL就会变成野指针
		}
	}

	//进栈
	void Push(SElemType e)
	{
		if (top - base == stacksize)//栈满，分配空间
		{
			SElemType* base1 = new SElemType[stacksize + StackIncrement];
			for (int i = 0;i < stacksize;i++)//转移元素
			{
				base1[i] = base[i];
			}
			delete[]base;//释放空间
			base = base1;
			top = base + stacksize;
			stacksize += StackIncrement;
		}
		*top++ = e;
	}

	//出栈
	void Pop(SElemType& e)
	{
		if (top == base)return;//栈为空，出栈操作不合法
		e = *--top;
	}

	//获取栈顶元素
	SElemType GetTop()
	{
		if (top == base)
		{
			cout << "栈空，栈顶无元素";
			exit(-1);
		}
		return *(top - 1);
	}

	//输出栈中元素
	void PrintStack()
	{
		SElemType* p = base;
		while (p != top)
		{
			cout << *p;
			p++;
		}
	}

};