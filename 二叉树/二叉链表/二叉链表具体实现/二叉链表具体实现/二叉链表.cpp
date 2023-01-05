#include <iostream>
using namespace std;

#define MAX_SIZE 128
#define STR_SIZE 1024
#define _CRT_SECURE_NO_WARNINGS


//定义二叉链表
typedef struct BiTNode
{
	char data;//数据元素信息
	int weight;//权值
	BiTNode* lchild;//指向左孩子结点
	BiTNode* rchild;//指向右孩子结点
}BiTNode, * BiTree;

//定义顺序队列
typedef struct Quene {      // 定义顺序队
	int     front;          // 队头指针
	int     rear;           // 队尾指针
	BiTree data[MAX_SIZE]; // 存放队中元素
} SqQueue;

//队列函数
void InitQueue(SqQueue** q);            // 初始化队列
bool EmptyQueue(SqQueue* q);            // 判断队列空
bool EnQueue(SqQueue* q, BiTree node);  // 入队
bool DeQueue(SqQueue* q, BiTree* node); // 出队
void LevelTraverse(BiTree T);           //层次遍历

//二叉链表函数
void Create_D(BiTree& T);               //按先序遍历序列建立二叉树的二叉链表
void PreTraverse(BiTree T);             //先序遍历递归函数
void InTraverse(BiTree T);              //中序遍历递归函数
void PostTraverse(BiTree T);            //后序遍历递归函数
int Depth(BiTree T);                    //深度
int Leaf(BiTree T);                     //树叶数
int Count(BiTree T);                    //结点数
int SearchXNum(BiTree T, int x);        //计算二叉树中结点的值大于x的结点的个数
int Node_2(BiTree T);                 //计算二叉树中度为2的结点数。

//画树
void Draw_level(BiTree node, bool left, char* str); // 画分支                       
void Draw(BiTree root);                 // 画根节点

//菜单函数
void showMenu();

int main()
{

	int select = 0;//创建用户选择输入的变量
	BiTree T;
	while (true)
	{
		//例子：A5B7D4H1###E7##C8F8##G9##
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1、构造二叉树
			cout << "请输入先序遍历序列：";
			Create_D(T);
			cout << "二叉树创建成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 2://2、先序遍历
			cout << "先序遍历结果是：";
			PreTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3://3、中序遍历
			cout << "中序遍历结果是：";
			InTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 4://4、后序遍历
			cout << "后序遍历结果是：";
			PostTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5://5、层次遍历
			cout << "层次遍历结果是：";
			LevelTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6://6、求二叉树深度
			cout << "二叉树深度是：" << Depth(T) << endl;
			system("pause");
			system("cls");
			break;
		case 7://7、求结点数
			cout << "二叉树结点数是：" << Count(T) << endl;
			system("pause");
			system("cls");
			break;

		case 8://8、求叶子结点数
			cout << "二叉树树叶数是：" << Leaf(T) << endl;
			system("pause");
			system("cls");
			break;

		case 9://9、计算二叉树中结点的值大于x的结点的个数
			int x;
			cout << "请输入x的值：";
			cin >> x;
			cout << "二叉树中结点的值大于" << x << "的结点数：" << SearchXNum(T, x) << endl;
			system("pause");
			system("cls");
			break;

		case 10://10、计算二叉树中度为2的结点数
			cout << "二叉树中度为2的结点数：" << Node_2(T) << endl;
			system("pause");
			system("cls");
			break;

		case 11://11、画树
			cout << "二叉树：" << endl;
			Draw(T);
			system("pause");
			system("cls");
			break;
		case 0://0、退出程序
			cout << "下次见！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;

		}
	}

	system("pause");

	return 0;
}

//菜单
void showMenu()
{
	cout << "-----------------------------------------------" << endl;
	cout << "|  1、先序序列构造二叉树  ----------------------" << endl;
	cout << "|  2、先序遍历          ----------------------" << endl;
	cout << "|  3、中序遍历          ----------------------" << endl;
	cout << "|  4、后序遍历          ----------------------" << endl;
	cout << "|  5、层次遍历          ----------------------" << endl;
	cout << "|  6、求二叉树深度       ----------------------" << endl;
	cout << "|  7、求结点数          ----------------------" << endl;
	cout << "|  8、求叶子结点数       ----------------------" << endl;
	cout << "|  9、计算二叉树中结点的值大于x的结点的个数   ------" << endl;
	cout << "| 10、计算二叉树中度为2的结点数             ------" << endl;
	cout << "| 11、画树                              ------" << endl;
	cout << "|  0、退出程序                           ------" << endl;
	cout << "---------------------------------------------" << endl;
}

//按先序遍历序列建立二叉树的二叉链表
void Create_D(BiTree& T)
{
	char node;
	int value;
	cin >> node;
	if (node == '#')T = NULL;
	else
	{
		cin >> value;
		T = new BiTNode;
		//D
		T->data = node;
		T->weight = value;
		//L
		Create_D(T->lchild);
		//R
		Create_D(T->rchild);
	}
}

//先序遍历递归函数
void PreTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << " ";//访问根结点
		PreTraverse(T->lchild);//先序遍历左子树
		PreTraverse(T->rchild);//先序遍历右子树
	}
}

//中序遍历递归函数
void InTraverse(BiTree T)
{
	if (T)
	{
		InTraverse(T->lchild);//中序遍历左子树
		cout << T->data << " ";//访问根结点
		InTraverse(T->rchild);//中序遍历右子树
	}
}

//后序遍历递归函数
void PostTraverse(BiTree T)
{
	if (T)
	{
		PostTraverse(T->lchild);//后序遍历左子树	
		PostTraverse(T->rchild);//后序遍历右子树
		cout << T->data << " ";//访问根结点
	}
}

//深度
int Depth(BiTree T)
{
	if (T == NULL)return 0;
	else
	{
		int m = 1 + Depth(T->lchild);//计算左子树的树高
		int n = 1 + Depth(T->rchild);//计算右子树的树高
		if (m >= n)return m;//比较左右子树的高度
		else return n;
	}
}

//树叶数
int Leaf(BiTree T)
{
	if (T == NULL)return 0;
	else
	{
		int m = Leaf(T->lchild);//计算左子树的树叶数
		int n = Leaf(T->rchild);//计算右子树的树叶数
		if (m + n == 0)return 1;//比较左右子树的树叶数
		else return m + n;
	}
}

//结点数
int Count(BiTree T)
{
	if (T == NULL)return 0;
	if (!T->lchild && !T->rchild)return 1;
	else
	{
		int m = Count(T->lchild);
		int n = Count(T->rchild);
		return m + n + 1;
	}

}

//计算二叉树中结点的值大于x的结点的个数
int SearchXNum(BiTree T, int x)
{
	int n;
	if (T == NULL)return 0;
	if (T->weight > x)n = 1;
	else n = 0;
	return n + SearchXNum(T->lchild, x) + SearchXNum(T->rchild, x);
}

//计算二叉树中度为2的结点数。
int Node_2(BiTree T)
{
	if (T == NULL)return 0;
	else if (T->lchild && T->rchild)return Node_2(T->lchild) + Node_2(T->rchild) + 1;
	else return Node_2(T->lchild) + Node_2(T->rchild);
}

//初始化队列
void InitQueue(SqQueue** q) {
	if (!(*q = new SqQueue[MAX_SIZE]))
	{
		printf("内存分配失败！");
		exit(-1);
	}
	(*q)->front = (*q)->rear = -1; // 置 -1
}

//判断队列是否为空
bool EmptyQueue(SqQueue* q) {
	// 首指针和尾指针相等，说明为空。空-返回真，不空-返回假
	if (q->front == q->rear)return true;
	return false;
}

//进队列
bool EnQueue(SqQueue* q, BiTree node) {
	// 判断队列是否满了。满（插入失败）-返回假，不满（插入成功）-返回真
	if (q->rear == MAX_SIZE - 1)return false;
	q->rear++;               // 头指针加 1
	q->data[q->rear] = node; // 传值
	return true;
}

//出队列
bool DeQueue(SqQueue* q, BiTree* node) {
	// 判断是否空了。空（取出失败）-返回假，不空（取出成功）-返回真
	if (q->front == q->rear)return false;
	q->front++;                // 尾指针加 1
	*node = q->data[q->front]; // 取值
	return true;
}

//层次遍历
void LevelTraverse(BiTree T) {
	SqQueue* q;       // 定义队列
	InitQueue(&q);    // 初始化队列
	if (T) EnQueue(q, T);// 根节点指针进队列
	// 一层一层的把节点存入队列，当没有孩子节点时就不再循环
	while (!EmptyQueue(q)) {      // 队不为空循环
		DeQueue(q, &T);          // 出队时的节点
		cout << T->data;   // 输出节点存储的值
		if (T->lchild) EnQueue(q, T->lchild);//左子树的根结点入队
		if (T->rchild) EnQueue(q, T->rchild);//右子树的根节点入队
	}
}

// 画分支
void Draw_level(BiTree node, bool left, char* str) {
	if (node->rchild) {
		Draw_level(node->rchild, false, strcat(str, (left ? "|     " : "      ")));
	}

	cout << str;
	cout << (left ? '\\' : '/');
	cout << "-----";
	cout << node->data << "(" << node->weight << ")" << endl;

	if (node->lchild) {
		Draw_level(node->lchild, true, strcat(str, (left ? "      " : "|     ")));
	}
	//  "      " : "|     " 长度为 6
	str[strlen(str) - 6] = '\0';
}

// 画根节点
void Draw(BiTree root)
{
	char str[STR_SIZE];
	memset(str, '\0', STR_SIZE);

	if (root->rchild) {
		Draw_level(root->rchild, false, str);
	}
	cout << root->data << endl;
	if (root->lchild) {
		Draw_level(root->lchild, true, str);
	}
}
