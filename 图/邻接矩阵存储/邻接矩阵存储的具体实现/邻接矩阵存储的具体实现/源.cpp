#include <iostream>
using namespace std;

#define MaxVex 100 //Ԥ����󶥵���
const int MAXINT = 0xfffffff;//�����������ʾ�����

typedef char VElemType;//�趥�����������Ϊ�ַ���
typedef int ArcBox;//����ߵ�Ȩֵ����Ϊ����

typedef struct
{
	VElemType vexs[MaxVex];//�����
	ArcBox arcs[MaxVex][MaxVex];//�ڽӾ���
	int vexnum;//������
	int arcnum;//����
	int kind;//�ڽӾ���洢��ͼ������
}AMGraph;//Adjacency Matrix Graph

class Graph
{
private:
	AMGraph amg;

public:

	//����ͼ
	void CreateGraph()
	{
		cout << "����ͼ�����ࣺ1������ͼ 2������ͼ 3�������� 4��������";
		cin >> amg.kind;
		switch (amg.kind)
		{
			case 1:
				CreateDG();//��������ͼ
				break;
			case 2:
				CreateUDG();//��������ͼ
				break;
			case 3:
				CreateDN();//����������
				break;
			case 4:
				CreateUDN();//����������
				break;
		}
	}

	//��λ
	int LocateVex(VElemType x)
	{
		for (int i = 0;i < amg.vexnum;i++)
		{
			if (x == amg.vexs[i]) return i;
		}
		return -1;
	}

	//����������
	void CreateUDN()
	{
		VElemType v1, v2;
		ArcBox w;

		cin >> amg.vexnum >> amg.arcnum;//�����ܶ��������ܱ���

		for (int i = 0;i < amg.vexnum;i++)
		{
			cin >> amg.vexs[i];//������������Ϣ
		}

		for (int i = 0;i < amg.vexnum;i++)//��ʼ���ڽӾ���
		{
			for (int j = 0;j < amg.vexnum;j++)
			{
				amg.arcs[i][j] = MAXINT;//�ߵ�Ȩֵ����Ϊ����ֵ
			}
		}

		for (int k = 0;k < amg.arcnum;k++)//�����ڽӾ���
		{
			cin >> v1 >> v2 >> w;//����һ�����������Ķ��㼰�ߵ�Ȩֵ
			int i = LocateVex(v1);
			int j = LocateVex(v2);//ȷ��v1��v2��amg�е�λ��
			amg.arcs[i][j] = w;//Ȩֵ��Ϊw
			amg.arcs[j][i] = w;//amg.arcs[i][j];
		}

	}
};