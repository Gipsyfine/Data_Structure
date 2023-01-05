#include <iostream>
using namespace std;

#define MaxVex 100 //预设最大顶点数
const int MAXINT = 0xfffffff;//最大整数，表示无穷大

typedef char VElemType;//设顶点的数据类型为字符型
typedef int ArcBox;//假设边的权值类型为整型

typedef struct
{
	VElemType vexs[MaxVex];//顶点表
	ArcBox arcs[MaxVex][MaxVex];//邻接矩阵
	int vexnum;//顶点数
	int arcnum;//边数
	int kind;//邻接矩阵存储的图的种类
}AMGraph;//Adjacency Matrix Graph

class Graph
{
private:
	AMGraph amg;

public:

	//创建图
	void CreateGraph()
	{
		cout << "输入图的种类：1：有向图 2：无向图 3：有向网 4：无向网";
		cin >> amg.kind;
		switch (amg.kind)
		{
			case 1:
				CreateDG();//构造有向图
				break;
			case 2:
				CreateUDG();//构造无向图
				break;
			case 3:
				CreateDN();//构造有向网
				break;
			case 4:
				CreateUDN();//构造无向网
				break;
		}
	}

	//定位
	int LocateVex(VElemType x)
	{
		for (int i = 0;i < amg.vexnum;i++)
		{
			if (x == amg.vexs[i]) return i;
		}
		return -1;
	}

	//构造无向网
	void CreateUDN()
	{
		VElemType v1, v2;
		ArcBox w;

		cin >> amg.vexnum >> amg.arcnum;//输入总顶点数，总边数

		for (int i = 0;i < amg.vexnum;i++)
		{
			cin >> amg.vexs[i];//依次输入点的信息
		}

		for (int i = 0;i < amg.vexnum;i++)//初始化邻接矩阵
		{
			for (int j = 0;j < amg.vexnum;j++)
			{
				amg.arcs[i][j] = MAXINT;//边的权值均置为极大值
			}
		}

		for (int k = 0;k < amg.arcnum;k++)//构造邻接矩阵
		{
			cin >> v1 >> v2 >> w;//输入一条边所依附的顶点及边的权值
			int i = LocateVex(v1);
			int j = LocateVex(v2);//确定v1和v2在amg中的位置
			amg.arcs[i][j] = w;//权值置为w
			amg.arcs[j][i] = w;//amg.arcs[i][j];
		}

	}
};