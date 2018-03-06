//dfs-递归-邻接矩阵-无向图
//bfs-非递归-邻接表-有向图
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 100
#define inf 0x3f3f3f3f  //表示两点之间没有边相连
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
typedef struct Adjacency_List {
	VNode AdjList[MAXN];
	int vertexnum, arcnum;
}Adjacency_List;            //定义图类型

//邻接矩阵定义类型
typedef struct Adjacency_Matrix
{
    char vertex[MAXN]; //存储顶点信息
    int arc[MAXN][MAXN]; //存储边信息
    int vertexnum,arcnum;//存储顶点数和边数
} Adjacency_Matrix;


void Init_A_M(Adjacency_Matrix *M)
{
    int i,j,k;
    printf("输入构造的无向图的顶点数和边数：\n");
    scanf("%d %d",&M->vertexnum,&M->arcnum);

    printf("输入无向图顶点信息：\n");
    char ch;
    while( ( ch = getchar() != '\n' ) );  //过滤掉前面的\n，防止\n被scanf进去
    for(i=0; i<M->vertexnum; i++)
        scanf("%c",&M->vertex[i]);

    //不相连的顶点之间的权值设为inf，包括顶点自身
    //初始化邻接矩阵
    for(i=0; i<M->vertexnum; i++)
        for(j=0; j<M->vertexnum; j++)
            M->arc[i][j] = inf;

    //更新无向图边信息
    printf("输入无向图邻接矩阵相连的边信息\n");
    for(k=0; k<M->arcnum; k++)
    {
        scanf("%d %d",&i,&j);
        M->arc[i][j] = 1;
        M->arc[j][i] = M->arc[i][j];//无向图是对称阵
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
	scanf("%d%d", &L.vertexnum, &L.arcnum);
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
void DFS(Adjacency_Matrix M, int v)
{
    int j;
    if (!visited[v])
    {
        printf("%c ",M.vertex[v]);
        visited[v] = 1; //标记为访问过
    }

    for (j = 0; j < M.vertexnum; j++)
        if (M.arc[v][j] && !visited[j])   //邻接矩阵的第(v,j)元素不为0
        {
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
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);

	Adjacency_List L;
	printf("广度优先搜索-非递归-邻接表-有向图的遍历：\n");
	Init_A_L(L);
	ArcNode p;
	p = L.AdjList[0].firstarc;
	memset(visited, 0, sizeof(visited));
	printf("遍历结果：\n");
	BFS(L);
	putchar('\n');

    Adjacency_Matrix M;
    memset(visited, 0, sizeof(visited));
    printf("深度优先搜索-递归-邻接矩阵-无向图的遍历：\n");
    Init_A_M(&M);
    printf("遍历结果：\n");
    DFS(M, 0);
    putchar('\n');
}
