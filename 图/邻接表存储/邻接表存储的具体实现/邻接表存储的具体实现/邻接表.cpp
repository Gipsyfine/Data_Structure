#include<iostream>
#define MaxVertexNum 30		//最大顶点数30

using namespace std;

bool visited[MaxVertexNum];	//区分顶点是否被访问的标志数组，初值为false
typedef int VertexType;
typedef int DataType;

typedef struct node 
{		//边结点
	int adjvertex;
	struct node* next;
}EdgeNode;


typedef struct vnode 
{		//表头结点
	VertexType vertex;
	EdgeNode* firstedge;
}VertexNode;

typedef struct 
{		//图
	VertexNode adjlist[MaxVertexNum];//邻接表
	int vertexNum, edgeNum;//顶点数和边数
}ALGraph;


typedef struct
{		//队列
	DataType data[MaxVertexNum];//数据域
	int front, rear;//队头和队尾指针
}SeqQueue, * PSeqQueue;

void Create_ALGraph(ALGraph* G);			//创建图
void DFS(ALGraph* G, int v);				//深度优先搜索算法
void DFStraverse(ALGraph* G);				//深度优先
void BFS(ALGraph* G, int v);				//广度优先搜索算法
void BFStraverse(ALGraph* G);				//广度优先

PSeqQueue Init_SeqQueue(void);				//循环队列初始化
int Empty_SeqQueue(PSeqQueue Q);			//判断队空
void In_SeqQueue(PSeqQueue Q, DataType x);	//入队
void Out_SeqQueue(PSeqQueue Q, DataType* y);//出队

int main() {
	cout << "创建图" << endl;
	ALGraph* G = new ALGraph;
	Create_ALGraph(G);

	cout << endl;
	cout << "深度优先遍历（图）：";
	DFStraverse(G);
	cout << "\b\b";
	cout << "    ";
	cout << "广度优先遍历（图）：";
	BFStraverse(G);
	cout << "\b\b";

	cout << "    ";

	system("pause");

	return 0;
}

//创建图
void Create_ALGraph(ALGraph* G) 
{
	int i, j, k;
	cout << "请输入图的顶点数和边数：";
	cin >> G->vertexNum >> G->edgeNum;

	cout << "输入" << G->vertexNum << "个顶点的表示形式：";
	for (i = 0;i < G->vertexNum;i++) {
		cin >> G->adjlist[i].vertex;	//顶点是数字
		G->adjlist[i].firstedge = NULL;//顶点的边表头指针设为空
	}

	VertexType v1, v2;
	EdgeNode* p;
	for (k = 0;k < G->edgeNum;k++) {
		//根据顶点序号查找指定顶点
		cout << "读入边(Vi,Vj)起点和终点对应的序号：";
		cin >> v1 >> v2;
		for (i = 0;v1 != G->adjlist[i].vertex;i++);
		for (j = 0;v2 != G->adjlist[j].vertex;j++);

		p = new EdgeNode;
		p->adjvertex = j;							
		p->next = G->adjlist[i].firstedge;//将新边表结点插入到顶点Vi的链表头部
		G->adjlist[i].firstedge = p;

		p = new EdgeNode;
		p->adjvertex = i;
		p->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = p;
	}
}

//深度优先搜索算法
void DFS(ALGraph* G, int v) 
{
	int w;
	EdgeNode* p;
	cout << G->adjlist[v].vertex << "->";

	visited[v] = true;//访问第v个顶点，并把访问标志置true
	for (p = G->adjlist[v].firstedge;p;p = p->next) {
		w = p->adjvertex;
		if (!visited[w])//对v尚未访问的邻接顶点w递归调用DFS
			DFS(G, w);
	}
}

//深度优先
void DFStraverse(ALGraph* G) 
{
	int v;
	for (v = 0;v < G->vertexNum;v++)
		visited[v] = false;
	for (v = 0;v < G->vertexNum;v++) {
		if (!visited[v])
			DFS(G, v);
	}
}

//广度优先搜索算法
void BFS(ALGraph* G, int v) 
{
	int u, w;
	EdgeNode* p;

	cout << G->adjlist[v].vertex << "->";
	visited[v] = true;//访问第v个顶点，并把访问标志置true
	PSeqQueue Q = Init_SeqQueue();
	In_SeqQueue(Q, v);

	while (!Empty_SeqQueue(Q)) {
		Out_SeqQueue(Q, &u);
		for (p = G->adjlist[u].firstedge;p;p = p->next) {
			w = p->adjvertex;
			if (!visited[w]) {//对v尚未访问的邻接顶点w入队列Q
				cout << G->adjlist[w].vertex << "->";
				visited[w] = true;
				In_SeqQueue(Q, w);
			}
		}
	}
}

//广度优先
void BFStraverse(ALGraph* G) 
{
	int v;
	for (v = 0;v < G->vertexNum;v++)
		visited[v] = false;
	for (v = 0;v < G->vertexNum;v++) {
		if (!visited[v])
			BFS(G, v);
	}
}

//循环队列初始化
PSeqQueue Init_SeqQueue() 
{
	PSeqQueue Q;
	Q = new SeqQueue;
	if (Q) {
		Q->front = 0;
		Q->rear = 0;
	}
	return Q;
}

//判断队空
int Empty_SeqQueue(PSeqQueue Q) 
{
	if (Q && Q->front == Q->rear)
		return 1;
	else
		return 0;
}

//入队
void In_SeqQueue(PSeqQueue Q, DataType x) 
{
	if (Q->front == (Q->rear + 1) % MaxVertexNum) {
		cout << "队满不能入队！";
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MaxVertexNum;
		Q->data[Q->rear] = x;
	}
}

//出队
void Out_SeqQueue(PSeqQueue Q, DataType* y) 
{
	if (Empty_SeqQueue(Q)) {
		cout << "队空不能出队！";
		return;
	}
	else {
		Q->front = (Q->front + 1) % MaxVertexNum;
		*y = Q->data[Q->front];
	}
}