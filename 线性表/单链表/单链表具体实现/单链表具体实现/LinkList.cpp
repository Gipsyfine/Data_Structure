#include "LinkList.h"

//构造空链表（构造函数）
LinkList::LinkList()
{
	head = new LNode;
	head->next = NULL;
}

//销毁链表（析构函数）
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

//建立具有n个数据元素的单链表：头插法--元素插入在链表头部，也叫前插法
void LinkList::CreateList_H(int n)
{
	LNode* s;
	for (int i = n;i > 0;i--)
	{
		s = new LNode;//生成新结点
		cin >> s->data;//倒位序输入元素值，因为是头插法
		s->next = head->next;//插入到表头
		head->next = s;
	}
}

//建立具有n个数据元素的单链表：尾插法--元素插入在链表尾部，也叫后插法
void LinkList::CreateList_T(int n)
{
	LNode* r = head;//尾指针r指向头结点
	LNode* s;
	for (int i = 0;i < n;i++)
	{
		s = new LNode;//生成新结点
		cin >> s->data;//正位序输入元素值，因为是尾插法
		s->next = NULL;//尾结点指针域为空
		r->next = s;//插入到表尾
		r = s;//r指向新的尾结点
	}
}

//求单链表的长度
int LinkList::ListLength()
{
	LNode* p = head->next;//p指向第一个结点
	int count = 0;
	while (p)//遍历单链表，统计结点数
	{
		count++;
		p = p->next;
	}
	return count;//返回结点的数量
}

//获取单链表的第i个数据元素，并将其数据域赋值给e
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
		return 0;//不存在第i个结点，返回 0
	}
	else
	{
		e = p->data;
		return 1;//存在第i个结点，返回 1
	}
}

//修改单链表的第i个数据元素
void LinkList::ChangeElem(int i)
{
	int count = 1;
	LNode* p = head->next;
	while (p != NULL)//判断是否为空链表
	{
		if (count == i)
		{
			cin >> p->data;
		}
		p = p->next;
		count++;
	}
}

//在单链表的第i个位置插入数据元素e
void LinkList::InsertList(int i, ElemType e)
{
	LNode* p = head;//初始化工作指针
	LNode* s;
	int j = 0;//初始化计数器
	while (p && j < i - 1)//查找第i-1个结点，并将p指向该结点
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)//插入位置不合理，异常处理
	{
		return;
	}
	else//查找成功，生成值为e的新结点s，并将s插入指针p所指结点的后面
	{
		s = new LNode;//生成新结点
		s->data = e;
		s->next = p->next;//插入新结点
		p->next = s;
	}
}

//删除表中第i个位置上的数据元素，保存数据元素的值到e
void LinkList::DeleteList(int i, ElemType& e)
{
	LNode* p = head;//初始化工作指针
	int j = 0;//初始化计数器
	while (p->next && j < i - 1)//查找第i-1个结点，并将p指向该结点
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)//删除位置不合理，异常处理
	{
		return;
	}
	else
	{
		LNode* q = p->next;
		e = q->data;//保存待删除结点的数据元素
		p->next = q->next;//删除结点
		delete q;//释放空间
	}
}

//查找单链表中值为e的数据元素（返回该数据元素的地址）
LNode* LinkList::LocateElem(ElemType e)
{
	LNode* p = head->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;//找到，则返回链表中值为e的数据元素的地址，查找失败返回NULL
}

//查找单链表中值为e的数据元素（返回该数据元素的位置序号）
int LinkList::LocateElem2(ElemType e)
{
	LNode* p = head->next;
	int count = 1;//初始化计数器
	while (p && p->data != e)
	{
		p = p->next;
		count++;
	}
	if (p)//找到，则返回链表中值为e的数据元素的位置序号，查找失败返回0
	{
		return count;
	}
	else
	{
		return 0;
	}

}

//输出单链表数据元素
void LinkList::Output()
{
	LNode* p = head->next;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}

