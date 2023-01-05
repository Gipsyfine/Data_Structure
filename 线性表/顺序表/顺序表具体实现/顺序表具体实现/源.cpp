//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//#define initlistsize 100
//#define increment 10
//
//typedef int ElemType;
//
//class SqList
//{
//
//private:
//	ElemType* elem;//存放数组的首地址
//	int listsize, length;//当前顺序表空间的大小和元素的数量
//
//public:
//
//	//初始化顺序表(构造函数)
//	SqList()//创建一个长度为0，容量为initlistsize的空表
//	{
//		elem = new ElemType[initlistsize];//申请大小为initlistsize的空间
//		listsize = initlistsize;//设置当前顺序表的空间大小
//		length = 0;//设置当前顺序表的元素数量为0
//	}
//
//	//销毁顺序表(析构函数)
//	~SqList()
//	{
//		delete[]elem;//释放顺序表占用的存储空间
//		listsize = 0;
//		length = 0;
//	}
//
//	//创建n个元素的顺序表
//
//	void CreateList(int n)
//	{
//		if (n<0 || n>initlistsize)return;//n非法
//		for (int i = 0; i < n; i++)
//		{
//			cin >> elem[i];
//			length++;
//		}
//	}
//	//查找元素值
//	int LocateList(ElemType x)
//	{
//		for (int i = 0;i < length;i++)
//		{
//			if (x == elem[i])
//			{
//				return i+1;//找到元素x，返回位置
//			}
//		}
//		return -1;
//	}
//
//	//插入数据元素
//	void InsertList(int i, ElemType e)//i是插入位置,e是数据元素
//	{
//		if (i<1 || i>length + 1)return;//插入位置不合理，作出错处理
//		if (length >= listsize)//顺序表已满，申请新空间
//		{
//			ElemType* elem1 = new ElemType[listsize + increment];//分配新空间
//			for (int j = 0;j < length;j++)
//			{
//				elem1[j] = elem[j];//复制元素
//			}
//			delete[]elem;//释放旧空间
//			elem = elem1;
//			listsize += increment;//调整顺序表的空间大小
//		}
//		for (int k = length - 1;k >= i - 1;k--)//插入位置及之后的元素后移(k是下标)
//		{
//			elem[k + 1] = elem[k];
//		}
//		elem[i - 1] = e;
//		length++;
//	}
//
//	//删除数据元素
//	void DeleteList(int i, ElemType& e)//i是删除位置
//	{
//		if (i<1 || i>length)return;
//		e = elem[i - 1];
//		for (int j = i;j <= length - 1;j++)//j是下标
//		{
//			elem[j - 1] = elem[j];//被删除元素之后的元素前移
//		}
//		length--;
//	}
//
//	//顺序表的取值（根据位置i获取相应位置数据元素的内容--顺序表的这种机制称为随机存取）
//	void GetElem(int i, ElemType& e)
//	{
//		if (i<1 || i>length) return;//判断i值是否合理，若不合理，无返回
//		e = elem[i - 1];//i的下标是i-1
//	}
//
//	//清空顺序表
//	void ClearList()
//	{
//		length = 0;//将线性表的长度置为0
//	}
//
//	//输出顺序表的长度
//	int GetLength()
//	{
//		return length;
//	}
//
//	//判断顺序表是否为空
//	int IsEmpty()
//	{
//		if (length == 0) return 1;
//		else return 0;
//	}
//
//	//倒置顺序表
//	void TurnList()
//	{
//		ElemType* p = elem, * q = &elem[length - 1];//取第一个元素和最后一个元素的首地址
//		ElemType* temp = new ElemType;
//		for (;p < q;p++, q--)//交换数据元素
//		{
//			*temp = *p;
//			*p = *q;
//			*q = *temp;
//		}
//	}
//
//	//合并顺序表
//	void Mergelist(SqList LA, SqList LB, SqList&LC)
//	{
//		LC.length = LA.length + LB.length;
//		ElemType* pa = LA.elem, * pa_last = &LA.elem[LA.length - 1];//两个表的第一个元素和最后一个元素
//		ElemType* pb = LB.elem, * pb_last = &LB.elem[LB.length - 1];
//
//		LC.elem = new ElemType[LC.length];//为新表分配空间
//		ElemType* pc = LC.elem;
//
//		//按值非递减合并LA和LB中的元素
//		while (pa <= pa_last && pb <= pb_last) 
//		{
//			if (*pa <= *pb) 
//			{
//				*pc++ = *pa++;
//			}
//			else 
//			{
//				*pc++ = *pb++;
//			}
//		}
//
//		// LB已到达表尾，将LA中剩余元素加入LC
//		while (pa <= pa_last) *pc++ = *pa++;
//
//		// LA已到达表尾，将LB中剩余元素加入LC
//		while (pb <= pb_last) *pc++ = *pb++;
//	}
//
//	//输出顺序表
//	void PrintList()
//	{
//		cout << "当前顺序表所有元素:" << endl;
//		for (int i = 0; i < length; i++)
//		{
//			cout << elem[i] << "\t";
//		}
//	}
//
//
//};
//
//int main()
//{
//	SqList L;
//	//建立具有n个数据元素的顺序表
//	int n;
//	cout << "请输入顺序表数据元素的个数：" << endl;
//	cin >> n;
//	cout << "请输入数据元素：" << endl;
//	L.CreateList(n);
//
//	//查找元素值
//	cout << "请输入要查找的数据元素：" << endl;
//	cin >> n;
//	int i = L.LocateList(n);
//	if (i != -1)
//	{
//		cout << "该元素的位置为：" << i << endl;
//	}
//	else
//	{
//		cout << "未找到！" << endl;
//	}
//
//	//插入数据元素
//	int k;
//	cout << "请输入要插入的位置和数据元素：" << endl;
//	cin >> n >> k;
//	L.InsertList(n, k);
//
//	//删除数据元素
//	int e;
//	cout << "请输入要删除的数据元素：" << endl;
//	cin >> i;
//	L.DeleteList(i, e);
//	cout << "删除的数据元素为：" << e << endl;
//	
//	//顺序表的取值
//	cout << "请输入要获取的数据元素：" << endl;
//	cin >> i;
//	L.GetElem(i, e);
//	cout << "第" << i << "个数据元素是" << e << endl;
//
//	//输出顺序表的长度
//	cout << L.GetLength() << endl;
//
//	//倒置顺序表
//	cout << "倒置顺序表" << endl;
//	L.TurnList();
//
//	//输出顺序表
//	L.PrintList();
//
//    system("pause");
//    return 0;
//}