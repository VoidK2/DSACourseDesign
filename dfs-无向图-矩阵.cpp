#include <cstdio>
#include <cstdlib>
#include <cstdbool>
using namespace std;

#define MAXN 100
#define inf 0x3f3f3f3f  //表示两点之间没有边相连

int visited[MAXN];   //标记顶点是否被访问

/**图的邻接矩阵的建立**/
//邻接矩阵数据结构定义
typedef struct Adjacency_Matrix
{
    char vertex[MAXN]; //存储顶点信息
    int arc[MAXN][MAXN]; //存储边信息
    int vertexnum,arcnum;//存储顶点数和边数
}Adjacency_Matrix;

void Create_non_direction_Adjacency_Matrix( Adjacency_Matrix *M )
{
    int i,j,k;
    printf("输入构造的无向图的顶点数和边数：\n");
    scanf("%d %d",&M->vertexnum,&M->arcnum);

    printf("输入无向图顶点信息：\n");
    char ch;
    while( ( ch = getchar() != '\n' ) );  //过滤掉前面的\n，防止\n被scanf进去
    for(i=0;i<M->vertexnum;i++)
        scanf("%c",&M->vertex[i]);

    //不相连的顶点之间的权值设为inf，包括顶点自身
    //初始化邻接矩阵
    for(i=0;i<M->vertexnum;i++)
        for(j=0;j<M->vertexnum;j++)
            M->arc[i][j] = inf;

    //更新无向图边信息
    printf("输入无向图邻接矩阵相连的边信息\n");
    for(k=0;k<M->arcnum;k++)
    {
        scanf("%d %d",&i,&j);
        M->arc[i][j] = 1;
        M->arc[j][i] = M->arc[i][j];//无向图是对称阵
    }
}

//从当前第i个顶点出发，DFS遍历
void DFS(Adjacency_Matrix M, int i)
{
    int j;
    //标记当前顶点为已访问状态
    visited[i] = true;
    printf("%c ",M.vertex[i]);

    //对与该顶点相连的其他未访问顶点进行DFS
    for(j=0;j<M.vertexnum;j++)
    {
        if( M.arc[i][j]==1 && !visited[j] )
            DFS(M,j);
    }
}
//对整个图进行DFS
void DFS_Travel(Adjacency_Matrix M)
{
    //整张图的DFS
    printf("对该无向图进行DFS的结果如下：\n");
    for(i=0;i<M.vertexnum;i++)
    {
        if( !visited[i] )
            DFS(M,i);
    }
}
int main()
{
    printf("测试代码\n");
    Adjacency_Matrix M;
    Create_non_direction_Adjacency_Matrix(&M);
    DFS_Travel(M);
    return 0;
}
