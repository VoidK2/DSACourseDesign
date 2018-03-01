//dfs-递归-邻接矩阵-无向图
//bfs-非递归-邻接表-有向图
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 100
using namespace std;

int visited[MAXN + 1];

//邻接表定义类型
typedef struct node {
	int data;
	struct node *next;
} Node, *ArcNode;          //定义边类型
typedef struct vnode {
	char data;
	ArcNode firstarc;
} VNode;                   //定义结点类型
struct Adjacency_List {
	VNode AdjList[MAXN];
	int vertexnum, arcnum;
};                         //定义图类型

//邻接矩阵定义类型
struct Adjacency_Matrix {
	int vertex[MAXN];     //定义结点
	int arc[MAXN][MAXN];   //定义边
	int vertexnum, arcnum; //定义总数
};


void Init_A_M(Adjacency_Matrix *&M) {
	int i, j;
	printf("请输入结点个数和边个数：\n");
	scanf("%d%d", &M->vertexnum, &M->arcnum); //输入顶点数和边数

	for (i = 0; i < M->vertexnum; i++) //输入每个顶点的值
		printf("请输入结点：\n");
	scanf("%d", &M->vertex[i]);
	//cin1 >> G->vertex[i];

	for (i = 0; i < M->vertexnum; i++) //初始化邻接矩阵
		for (j = 0; j < M->vertexnum; j++)
			M->arc[i][j] = 0;

	for (i = 0; i < M->arcnum; i++)
	{
		int n, m, w;
		printf("输入邻接矩阵的数据：\n");
		scanf("%d%d%d", &n, &m, &w);
		//cin1 >> n >> m >> w; //修改邻接矩阵中的值
		M->arc[n][m] = w;
		M->arc[m][n] = w;
	}

}
int LocateVex(char ch, Adjacency_List L)
{	//取该结点在数组中的位置
	int i;
	for (i = 0; i < L.vertexnum; i++)
		if (L.AdjList[i].data == ch)
			return i;
	return -1;
}
void Init_A_L(Adjacency_List &L) {
	int n, m;
	int i, j, k;
	char ch1, ch2;
	ArcNode p;
	printf("请输入结点个数和边个数：");
	scanf("%d %d", &L.vertexnum, &L.arcnum);
	printf("请输入结点：");
	getchar();
	for (i = 0; i < L.vertexnum; i++)
	{
		scanf("%c", &L.AdjList[i].data);
		L.AdjList[i].firstarc = NULL;
	}

	printf("请输入边：");
	for (k = 0; k < L.arcnum; k++)
	{
		getchar();
		scanf("%c %c", &ch1, &ch2);
		i = LocateVex(ch1, L); j = LocateVex(ch2, L);

		ArcNode e;
		e = (ArcNode)malloc(sizeof(Node));
		e->data = j;
		e->next = NULL;
		p = L.AdjList[i].firstarc;
		if (!p)
			L.AdjList[i].firstarc = e;
		else
		{
			while (p->next)
				p = p->next;
			p->next = e;
		}
	}
}
void DFS(Adjacency_Matrix *&M, int v) {
	int j;
	if (!visited[v]) {
		cout << M->vertex[v] << " ";
		visited[v] = 1; //标记为访问过
	}

	for (j = 0; j < M->vertexnum; j++)
		if (M->arc[v][j] && !visited[j]) { //邻接矩阵的第(v,j)元素不为0
			//且未被访问过则递归
			DFS(M, j);
		}

}
void BFS(Adjacency_List &L) {
	{	//广度优先搜索
		queue<int>q;
		int i, j;
		ArcNode p;
        for (i = 0; i < L.vertexnum; i++)
		{
			if (!visited[i])
			{
				visited[i] = 1;
				q.push(i);
				printf("%c ", L.AdjList[i].data);
				while (!q.empty())
				{
					p = L.AdjList[q.front()].firstarc;
					while (p)
					{
						if (!visited[p->data])
						{
							visited[p->data] = 1;
							printf("%c ", L.AdjList[p->data].data);
							q.push(p->data);
						}
						p = p->next;
					}
					q.pop();
				}
			}
		}
	}

}
int main() {
//    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);
	Adjacency_List L;
	Init_A_L(L);
	ArcNode p;
	p = L.AdjList[0].firstarc;
	memset(visited, 0, sizeof(visited));
	printf("广度优先搜索-非递归-邻接表-有向图的遍历：\n");
	BFS(L);
	putchar('\n');

	Adjacency_Matrix *M;
	memset(visited, 0, sizeof(visited));
	Init_A_M(M);
	printf("深度优先搜索-递归-邻接矩阵-无向图的遍历：\n");
	DFS(M, 0);
	putchar('\n');
}
