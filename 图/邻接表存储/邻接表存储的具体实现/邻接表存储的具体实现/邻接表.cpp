#include<iostream>
#define MaxVertexNum 30		//��󶥵���30

using namespace std;

bool visited[MaxVertexNum];	//���ֶ����Ƿ񱻷��ʵı�־���飬��ֵΪfalse
typedef int VertexType;
typedef int DataType;

typedef struct node 
{		//�߽��
	int adjvertex;
	struct node* next;
}EdgeNode;


typedef struct vnode 
{		//��ͷ���
	VertexType vertex;
	EdgeNode* firstedge;
}VertexNode;

typedef struct 
{		//ͼ
	VertexNode adjlist[MaxVertexNum];//�ڽӱ�
	int vertexNum, edgeNum;//�������ͱ���
}ALGraph;


typedef struct
{		//����
	DataType data[MaxVertexNum];//������
	int front, rear;//��ͷ�Ͷ�βָ��
}SeqQueue, * PSeqQueue;

void Create_ALGraph(ALGraph* G);			//����ͼ
void DFS(ALGraph* G, int v);				//������������㷨
void DFStraverse(ALGraph* G);				//�������
void BFS(ALGraph* G, int v);				//������������㷨
void BFStraverse(ALGraph* G);				//�������

PSeqQueue Init_SeqQueue(void);				//ѭ�����г�ʼ��
int Empty_SeqQueue(PSeqQueue Q);			//�ж϶ӿ�
void In_SeqQueue(PSeqQueue Q, DataType x);	//���
void Out_SeqQueue(PSeqQueue Q, DataType* y);//����

int main() {
	cout << "����ͼ" << endl;
	ALGraph* G = new ALGraph;
	Create_ALGraph(G);

	cout << endl;
	cout << "������ȱ�����ͼ����";
	DFStraverse(G);
	cout << "\b\b";
	cout << "    ";
	cout << "������ȱ�����ͼ����";
	BFStraverse(G);
	cout << "\b\b";

	cout << "    ";

	system("pause");

	return 0;
}

//����ͼ
void Create_ALGraph(ALGraph* G) 
{
	int i, j, k;
	cout << "������ͼ�Ķ������ͱ�����";
	cin >> G->vertexNum >> G->edgeNum;

	cout << "����" << G->vertexNum << "������ı�ʾ��ʽ��";
	for (i = 0;i < G->vertexNum;i++) {
		cin >> G->adjlist[i].vertex;	//����������
		G->adjlist[i].firstedge = NULL;//����ı߱�ͷָ����Ϊ��
	}

	VertexType v1, v2;
	EdgeNode* p;
	for (k = 0;k < G->edgeNum;k++) {
		//���ݶ�����Ų���ָ������
		cout << "�����(Vi,Vj)�����յ��Ӧ����ţ�";
		cin >> v1 >> v2;
		for (i = 0;v1 != G->adjlist[i].vertex;i++);
		for (j = 0;v2 != G->adjlist[j].vertex;j++);

		p = new EdgeNode;
		p->adjvertex = j;							
		p->next = G->adjlist[i].firstedge;//���±߱�����뵽����Vi������ͷ��
		G->adjlist[i].firstedge = p;

		p = new EdgeNode;
		p->adjvertex = i;
		p->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = p;
	}
}

//������������㷨
void DFS(ALGraph* G, int v) 
{
	int w;
	EdgeNode* p;
	cout << G->adjlist[v].vertex << "->";

	visited[v] = true;//���ʵ�v�����㣬���ѷ��ʱ�־��true
	for (p = G->adjlist[v].firstedge;p;p = p->next) {
		w = p->adjvertex;
		if (!visited[w])//��v��δ���ʵ��ڽӶ���w�ݹ����DFS
			DFS(G, w);
	}
}

//�������
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

//������������㷨
void BFS(ALGraph* G, int v) 
{
	int u, w;
	EdgeNode* p;

	cout << G->adjlist[v].vertex << "->";
	visited[v] = true;//���ʵ�v�����㣬���ѷ��ʱ�־��true
	PSeqQueue Q = Init_SeqQueue();
	In_SeqQueue(Q, v);

	while (!Empty_SeqQueue(Q)) {
		Out_SeqQueue(Q, &u);
		for (p = G->adjlist[u].firstedge;p;p = p->next) {
			w = p->adjvertex;
			if (!visited[w]) {//��v��δ���ʵ��ڽӶ���w�����Q
				cout << G->adjlist[w].vertex << "->";
				visited[w] = true;
				In_SeqQueue(Q, w);
			}
		}
	}
}

//�������
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

//ѭ�����г�ʼ��
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

//�ж϶ӿ�
int Empty_SeqQueue(PSeqQueue Q) 
{
	if (Q && Q->front == Q->rear)
		return 1;
	else
		return 0;
}

//���
void In_SeqQueue(PSeqQueue Q, DataType x) 
{
	if (Q->front == (Q->rear + 1) % MaxVertexNum) {
		cout << "����������ӣ�";
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MaxVertexNum;
		Q->data[Q->rear] = x;
	}
}

//����
void Out_SeqQueue(PSeqQueue Q, DataType* y) 
{
	if (Empty_SeqQueue(Q)) {
		cout << "�ӿղ��ܳ��ӣ�";
		return;
	}
	else {
		Q->front = (Q->front + 1) % MaxVertexNum;
		*y = Q->data[Q->front];
	}
}