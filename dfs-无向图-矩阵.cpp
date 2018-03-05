#include <cstdio>
#include <cstdlib>
#include <cstdbool>
using namespace std;

#define MAX_VERTEX 100
#define inf 65535  //表示两点之间没有边相连

int visit[MAX_VERTEX];   //标记顶点是否被访问

/**图的邻接矩阵的建立**/
//邻接矩阵数据结构定义
typedef struct Martrix_Graph
{
    char vertex[MAX_VERTEX]; //存储顶点信息
    int edge[MAX_VERTEX][MAX_VERTEX]; //存储边信息
    int vertex_number,edge_number;//存储顶点数和边数
}Martrix_Graph;

void Create_non_direction_martrix_Graph( Martrix_Graph *G )
{
    int i,j,k,m;
    printf("请输入构造的无向图的顶点数和边数：\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("请输入无向图顶点信息（如ABCDEF....）：\n");
    char ch;
    while( ( ch = getchar() != '\n' ) );  //过滤掉前面的\n，防止\n被scanf进去
    for(i=0;i<G->vertex_number;i++)
        scanf("%c",&G->vertex[i]);

    //不相连的顶点之间的权值设为inf，包括顶点自身
    //初始化邻接矩阵
    for(i=0;i<G->vertex_number;i++)
        for(j=0;j<G->vertex_number;j++)
            G->edge[i][j] = inf;

    //更新无向图边信息
    printf("请输入无向图邻接矩阵相连的边信息，相连标记为1\n");
    for(k=0;k<G->edge_number;k++)
    {
        scanf("%d %d %d",&i,&j,&m);
        G->edge[i][j] = m;
        G->edge[j][i] = G->edge[i][j];//无向图是对称阵
    }


    //打印邻接矩阵存储信息，检查正确性
    printf("---------------------构造出来的无向图邻接矩阵如下---------------------\n");
    for(i=0;i<G->vertex_number;i++)
    {
        for(j=0;j<G->vertex_number;j++)
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}

//从当前第i个顶点出发，DFS遍历
void DFS(Martrix_Graph G, int i)
{
    int j;
    //标记当前顶点为已访问状态
    visit[i] = true;
    printf("%c ",G.vertex[i]);

    //对与该顶点相连的其他未访问顶点进行DFS
    for(j=0;j<G.vertex_number;j++)
    {
        if( G.edge[i][j]==1 && !visit[j] )
            DFS(G,j);
    }
}
//对整个图进行DFS
void DFS_Travel(Martrix_Graph G)
{
    //初始化visit数组
    int i;
    for(i=0;i<G.vertex_number;i++)
        visit[i] = false;

    //整张图的DFS
    printf("对该无向图进行DFS的结果如下：\n");
    for(i=0;i<G.vertex_number;i++)
    {
        if( !visit[i] )
            DFS(G,i);
    }
}
int main()
{
    printf("测试代码\n");
    Martrix_Graph G;
    Create_non_direction_martrix_Graph(&G);
    DFS_Travel(G);
    return 0;
}
