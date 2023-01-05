//#include <iostream>
//using namespace std;
//
////问题描述：
////   实现带头结点的单链表的建立、求长度，取元素、修改元素、插入、删除等
////   单链表的基本操作。
//
//typedef int ElemType;
//
//typedef struct LNode
//{
//	ElemType data;
//	struct LNode* next;
//} LNode;
//
//class LinkList
//{
//private:
//	LNode* head;
//
//public:
//
//	//构造空链表（构造函数）
//	LinkList()
//	{
//		head = new LNode;
//		head->next = NULL;
//	}
//
//	//销毁链表（析构函数）
//	~LinkList()
//	{
//		LNode* p = head;
//		while (p)
//		{
//			head = head->next;
//			delete p;
//			p = head;
//		}
//	}
//
//	//建立具有n个数据元素的单链表：头插法--元素插入在链表头部，也叫前插法
//	void CreateList_H(int n)
//	{
//		LNode* s;
//		for (int i = n;i > 0;i--)
//		{
//			s = new LNode;//生成新结点
//			cin >> s->data;//倒位序输入元素值，因为是头插法
//			s->next = head->next;//插入到表头
//			head->next = s;
//		}
//	}
//
//	//建立具有n个数据元素的单链表：尾插法--元素插入在链表尾部，也叫后插法
//	void CreateList_T(int n)
//	{
//		LNode* r = head;//尾指针r指向头结点
//		LNode* s;
//		for (int i = 0;i < n;i++)
//		{
//			s = new LNode;//生成新结点
//			cin >> s->data;//正位序输入元素值，因为是尾插法
//			s->next = NULL;//尾结点指针域为空
//			r->next = s;//插入到表尾
//			r = s;//r指向新的尾结点
//		}
//	}
//
//	//求单链表的长度
//	int ListLength()
//	{
//		LNode* p = head->next;//p指向第一个结点
//		int count = 0;
//		while (p)//遍历单链表，统计结点数
//		{
//			count++;
//			p = p->next;
//		}
//		return count;//返回结点的数量
//	}
//
//	//获取单链表的第i个数据元素，并将其数据域赋值给e
//	int GetElem(int i, ElemType& e)
//	{
//		int j = 1;
//		LNode* p = head->next;
//		while (p && j < i)
//		{
//			p = p->next;
//			j++;
//		}
//		if (!p || j > i)
//		{
//			return 0;//不存在第i个结点，返回 0
//		}
//		else
//		{
//			e = p->data;
//			return 1;//存在第i个结点，返回 1
//		}
//	}
//
//	//修改单链表的第i个数据元素
//	void ChangeElem(int i)
//	{
//		int count = 1;
//		LNode* p = head->next;
//		while (p != NULL)//判断是否为空链表
//		{
//			if (count == i)
//			{
//				cin >> p->data;
//			}
//			p = p->next;
//			count++;
//		}
//	}
//
//	//在单链表的第i个位置插入数据元素e
//	void InsertList(int i, ElemType e)
//	{
//		LNode* p = head;//初始化工作指针
//		LNode* s;
//		int j = 0;//初始化计数器
//		while (p && j < i - 1)//查找第i-1个结点，并将p指向该结点
//		{
//			p = p->next;
//			j++;
//		}
//
//		if (!p || j > i - 1)//插入位置不合理，异常处理
//		{
//			return;
//		}
//		else//查找成功，生成值为e的新结点s，并将s插入指针p所指结点的后面
//		{
//			s = new LNode;//生成新结点
//			s->data = e;
//			s->next = p->next;//插入新结点
//			p->next = s;
//		}
//	}
//
//	//删除表中第i个位置上的数据元素，保存数据元素的值到e
//	void DeleteList(int i, ElemType& e)
//	{
//		LNode* p = head;//初始化工作指针
//		int j = 0;//初始化计数器
//		while (p->next && j < i - 1)//查找第i-1个结点，并将p指向该结点
//		{
//			p = p->next;
//			j++;
//		}
//		if (!p->next || j > i - 1)//删除位置不合理，异常处理
//		{
//			return;
//		}
//		else
//		{
//			LNode* q = p->next;
//			e = q->data;//保存待删除结点的数据元素
//			p->next = q->next;//删除结点
//			delete q;//释放空间
//		}
//	}
//
//	//查找单链表中值为e的数据元素（返回该数据元素的地址）
//	LNode* LocateElem(ElemType e)
//	{
//		LNode* p = head->next;
//		while (p && p->data != e)
//		{
//			p = p->next;
//		}
//		return p;//找到，则返回链表中值为e的数据元素的地址，查找失败返回NULL
//	}
//
//	//查找单链表中值为e的数据元素（返回该数据元素的位置序号）
//	int LocateElem2(ElemType e)
//	{
//		LNode* p = head->next;
//		int count = 1;//初始化计数器
//		while (p && p->data != e)
//		{
//			p = p->next;
//			count++;
//		}
//		if (p)//找到，则返回链表中值为e的数据元素的位置序号，查找失败返回0
//		{
//			return count;
//		}
//		else
//		{
//			return 0;
//		}
//		
//	}
//
//	//输出单链表数据元素
//	void Output()
//	{
//		LNode* p = head->next;
//		while (p)
//		{
//			cout << p->data << "\t";
//			p = p->next;
//		}
//	}
//
//
//};
//
//void showMenu()
//{
//	cout << "***************************" << endl;
//	cout << "*****  1、建立单链表   *****" << endl;
//	cout << "*****  2、求单链表长度  *****" << endl;
//	cout << "*****  3、获取数据元素  *****" << endl;
//	cout << "*****  4、修改数据元素  *****" << endl;
//	cout << "*****  5、插入数据元素  *****" << endl;
//	cout << "*****  6、查找数据元素  *****" << endl;
//	cout << "*****  7、删除数据元素  *****" << endl;
//	cout << "*****  0、输出单链表   *****" << endl;
//	cout << "***************************" << endl;
//}
//
//
//int main()
//{
//	LinkList L;
//	//建立具有n个数据元素的单链表
//	int n;
//	cout << "请输入单链表数据元素的个数：" << endl;
//	cin >> n;
//	cout << "请输入数据元素：" << endl;
//	L.CreateList_T(n);
//
//	//单链表的长度
//	cout << "单链表的长度为：" << endl;
//	cout << L.ListLength() << endl;
//
//	//获取单链表的第i个数据元素，并将其数据域赋值给e
//	int i,e=0;
//	cout << "获取单链表的第i个数据元素(请输入数字i)：" << endl;
//	cin >> i;
//	
//	int H = L.GetElem(i, e);
//	if (H != 0)
//	{
//		cout << "获取成功！" << endl;
//		cout << "该数据元素的值为：" << e << endl;
//	}
//	else
//	{
//		cout << "获取失败！不存在该结点。" << endl;
//	}
//
//	//修改单链表的第i个数据元素
//	cout << "修改单链表的第i个数据元素(请输入数字i)：" << endl;
//	cin >> i;
//
//	L.ChangeElem(i);
//
//	//在单链表的第i个位置插入数据元素e
//	cout << "在单链表的第i个位置插入数据元素(请输入数字i)：" << endl;
//	cin >> i;
//	cout << "新结点的值为：" << endl;
//	cin >> e;
//	L.InsertList(i, e);
//
//   //删除表中第i个位置上的数据元素，保存数据元素的值到e
//	cout << "删除单链表的第i个数据元素(请输入数字i)：" << endl;
//	cin >> i;
//	L.DeleteList(i, e);
//
//	//查找单链表中值为e的数据元素（返回该数据元素的位置序号）
//	cout << "请输入要查找的数据元素的值：" << endl;
//	cin >> e;
//	int Loc = L.LocateElem2(e);
//	if (Loc)
//	{
//		cout << "查找成功！" << endl;
//		cout << "位置序号为：" << Loc << endl;
//	}
//	else
//	{
//		cout << "未找到！" << endl;
//	}
//
//	//输出单链表数据元素
//	
//	L.Output();
//
//	system("pause");
//
//	return 0;
//}