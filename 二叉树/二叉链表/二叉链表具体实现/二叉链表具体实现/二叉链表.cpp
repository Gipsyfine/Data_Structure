#include <iostream>
using namespace std;

#define MAX_SIZE 128
#define STR_SIZE 1024
#define _CRT_SECURE_NO_WARNINGS


//�����������
typedef struct BiTNode
{
	char data;//����Ԫ����Ϣ
	int weight;//Ȩֵ
	BiTNode* lchild;//ָ�����ӽ��
	BiTNode* rchild;//ָ���Һ��ӽ��
}BiTNode, * BiTree;

//����˳�����
typedef struct Quene {      // ����˳���
	int     front;          // ��ͷָ��
	int     rear;           // ��βָ��
	BiTree data[MAX_SIZE]; // ��Ŷ���Ԫ��
} SqQueue;

//���к���
void InitQueue(SqQueue** q);            // ��ʼ������
bool EmptyQueue(SqQueue* q);            // �ж϶��п�
bool EnQueue(SqQueue* q, BiTree node);  // ���
bool DeQueue(SqQueue* q, BiTree* node); // ����
void LevelTraverse(BiTree T);           //��α���

//����������
void Create_D(BiTree& T);               //������������н����������Ķ�������
void PreTraverse(BiTree T);             //��������ݹ麯��
void InTraverse(BiTree T);              //��������ݹ麯��
void PostTraverse(BiTree T);            //��������ݹ麯��
int Depth(BiTree T);                    //���
int Leaf(BiTree T);                     //��Ҷ��
int Count(BiTree T);                    //�����
int SearchXNum(BiTree T, int x);        //����������н���ֵ����x�Ľ��ĸ���
int Node_2(BiTree T);                 //����������ж�Ϊ2�Ľ������

//����
void Draw_level(BiTree node, bool left, char* str); // ����֧                       
void Draw(BiTree root);                 // �����ڵ�

//�˵�����
void showMenu();

int main()
{

	int select = 0;//�����û�ѡ������ı���
	BiTree T;
	while (true)
	{
		//���ӣ�A5B7D4H1###E7##C8F8##G9##
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1�����������
			cout << "����������������У�";
			Create_D(T);
			cout << "�����������ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		case 2://2���������
			cout << "�����������ǣ�";
			PreTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3://3���������
			cout << "�����������ǣ�";
			InTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 4://4���������
			cout << "�����������ǣ�";
			PostTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5://5����α���
			cout << "��α�������ǣ�";
			LevelTraverse(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6://6������������
			cout << "����������ǣ�" << Depth(T) << endl;
			system("pause");
			system("cls");
			break;
		case 7://7��������
			cout << "������������ǣ�" << Count(T) << endl;
			system("pause");
			system("cls");
			break;

		case 8://8����Ҷ�ӽ����
			cout << "��������Ҷ���ǣ�" << Leaf(T) << endl;
			system("pause");
			system("cls");
			break;

		case 9://9������������н���ֵ����x�Ľ��ĸ���
			int x;
			cout << "������x��ֵ��";
			cin >> x;
			cout << "�������н���ֵ����" << x << "�Ľ������" << SearchXNum(T, x) << endl;
			system("pause");
			system("cls");
			break;

		case 10://10������������ж�Ϊ2�Ľ����
			cout << "�������ж�Ϊ2�Ľ������" << Node_2(T) << endl;
			system("pause");
			system("cls");
			break;

		case 11://11������
			cout << "��������" << endl;
			Draw(T);
			system("pause");
			system("cls");
			break;
		case 0://0���˳�����
			cout << "�´μ���" << endl;
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

//�˵�
void showMenu()
{
	cout << "-----------------------------------------------" << endl;
	cout << "|  1���������й��������  ----------------------" << endl;
	cout << "|  2���������          ----------------------" << endl;
	cout << "|  3���������          ----------------------" << endl;
	cout << "|  4���������          ----------------------" << endl;
	cout << "|  5����α���          ----------------------" << endl;
	cout << "|  6������������       ----------------------" << endl;
	cout << "|  7��������          ----------------------" << endl;
	cout << "|  8����Ҷ�ӽ����       ----------------------" << endl;
	cout << "|  9������������н���ֵ����x�Ľ��ĸ���   ------" << endl;
	cout << "| 10������������ж�Ϊ2�Ľ����             ------" << endl;
	cout << "| 11������                              ------" << endl;
	cout << "|  0���˳�����                           ------" << endl;
	cout << "---------------------------------------------" << endl;
}

//������������н����������Ķ�������
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

//��������ݹ麯��
void PreTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << " ";//���ʸ����
		PreTraverse(T->lchild);//�������������
		PreTraverse(T->rchild);//�������������
	}
}

//��������ݹ麯��
void InTraverse(BiTree T)
{
	if (T)
	{
		InTraverse(T->lchild);//�������������
		cout << T->data << " ";//���ʸ����
		InTraverse(T->rchild);//�������������
	}
}

//��������ݹ麯��
void PostTraverse(BiTree T)
{
	if (T)
	{
		PostTraverse(T->lchild);//�������������	
		PostTraverse(T->rchild);//�������������
		cout << T->data << " ";//���ʸ����
	}
}

//���
int Depth(BiTree T)
{
	if (T == NULL)return 0;
	else
	{
		int m = 1 + Depth(T->lchild);//����������������
		int n = 1 + Depth(T->rchild);//����������������
		if (m >= n)return m;//�Ƚ����������ĸ߶�
		else return n;
	}
}

//��Ҷ��
int Leaf(BiTree T)
{
	if (T == NULL)return 0;
	else
	{
		int m = Leaf(T->lchild);//��������������Ҷ��
		int n = Leaf(T->rchild);//��������������Ҷ��
		if (m + n == 0)return 1;//�Ƚ�������������Ҷ��
		else return m + n;
	}
}

//�����
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

//����������н���ֵ����x�Ľ��ĸ���
int SearchXNum(BiTree T, int x)
{
	int n;
	if (T == NULL)return 0;
	if (T->weight > x)n = 1;
	else n = 0;
	return n + SearchXNum(T->lchild, x) + SearchXNum(T->rchild, x);
}

//����������ж�Ϊ2�Ľ������
int Node_2(BiTree T)
{
	if (T == NULL)return 0;
	else if (T->lchild && T->rchild)return Node_2(T->lchild) + Node_2(T->rchild) + 1;
	else return Node_2(T->lchild) + Node_2(T->rchild);
}

//��ʼ������
void InitQueue(SqQueue** q) {
	if (!(*q = new SqQueue[MAX_SIZE]))
	{
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	(*q)->front = (*q)->rear = -1; // �� -1
}

//�ж϶����Ƿ�Ϊ��
bool EmptyQueue(SqQueue* q) {
	// ��ָ���βָ����ȣ�˵��Ϊ�ա���-�����棬����-���ؼ�
	if (q->front == q->rear)return true;
	return false;
}

//������
bool EnQueue(SqQueue* q, BiTree node) {
	// �ж϶����Ƿ����ˡ���������ʧ�ܣ�-���ؼ٣�����������ɹ���-������
	if (q->rear == MAX_SIZE - 1)return false;
	q->rear++;               // ͷָ��� 1
	q->data[q->rear] = node; // ��ֵ
	return true;
}

//������
bool DeQueue(SqQueue* q, BiTree* node) {
	// �ж��Ƿ���ˡ��գ�ȡ��ʧ�ܣ�-���ؼ٣����գ�ȡ���ɹ���-������
	if (q->front == q->rear)return false;
	q->front++;                // βָ��� 1
	*node = q->data[q->front]; // ȡֵ
	return true;
}

//��α���
void LevelTraverse(BiTree T) {
	SqQueue* q;       // �������
	InitQueue(&q);    // ��ʼ������
	if (T) EnQueue(q, T);// ���ڵ�ָ�������
	// һ��һ��İѽڵ������У���û�к��ӽڵ�ʱ�Ͳ���ѭ��
	while (!EmptyQueue(q)) {      // �Ӳ�Ϊ��ѭ��
		DeQueue(q, &T);          // ����ʱ�Ľڵ�
		cout << T->data;   // ����ڵ�洢��ֵ
		if (T->lchild) EnQueue(q, T->lchild);//�������ĸ�������
		if (T->rchild) EnQueue(q, T->rchild);//�������ĸ��ڵ����
	}
}

// ����֧
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
	//  "      " : "|     " ����Ϊ 6
	str[strlen(str) - 6] = '\0';
}

// �����ڵ�
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
