#include <iostream>
#include <cstdlib>

using namespace std;

#define InitStackSize 100
#define StackIncrement 10

typedef int SElemType;

class SqStack
{

private:
	SElemType* base, * top;//baseΪջ��ָ�룬topΪջ��ָ��
	int stacksize;//ջ����

public:

	//��ʼ����������ջ
	SqStack()
	{
		base = top = new SElemType[InitStackSize];
		stacksize = InitStackSize;
	}

	//����ջ
	~SqStack()
	{
		delete[]base;
		stacksize = 0;
	}

	//�ж�ջ�Ƿ�Ϊ��ջ
	int EmptyStack() 
	{
		if (top == base)return 1;//ջΪ�գ�����1
		else return 0;//ջΪ�ǿգ�����0
	}

	//��˳��ջ����
	int StackLength()
	{
		return top - base;
	}

	//���˳��ջ
	void ClearStack()
	{
		if (base)top = base;
	}

	//����˳��ջ
	void DestroyStack()
	{
		if (base)
		{
			delete base;
			stacksize = 0;
			base = top = NULL;//����ֵNULL�ͻ���Ұָ��
		}
	}

	//��ջ
	void Push(SElemType e)
	{
		if (top - base == stacksize)//ջ��������ռ�
		{
			SElemType* base1 = new SElemType[stacksize + StackIncrement];
			for (int i = 0;i < stacksize;i++)//ת��Ԫ��
			{
				base1[i] = base[i];
			}
			delete[]base;//�ͷſռ�
			base = base1;
			top = base + stacksize;
			stacksize += StackIncrement;
		}
		*top++ = e;
	}

	//��ջ
	void Pop(SElemType& e)
	{
		if (top == base)return;//ջΪ�գ���ջ�������Ϸ�
		e = *--top;
	}

	//��ȡջ��Ԫ��
	SElemType GetTop()
	{
		if (top == base)
		{
			cout << "ջ�գ�ջ����Ԫ��";
			exit(-1);
		}
		return *(top - 1);
	}

	//���ջ��Ԫ��
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