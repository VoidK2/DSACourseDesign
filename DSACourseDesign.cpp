#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
const int MAXN = 1e4 + 5;


//邻接表节点结构体
struct Node
{
    int v;                  //表示当前节点
    struct Node *next;      //表示连接的节点的指针域
} node[MAXN];
int que[MAXN];
int nodenum1,arcnum1;


//邻接矩阵声明变量
bool Map[MAXN][MAXN], visited[MAXN];
int nodenum2,arcnum2;


//初始化邻接表
void BFSInitMap()
{
    int i,j;
    for(int p = 1; p <= nodenum1; p++)
        node[p].v = p, node[p].next = NULL;        //node下标表示当前起始点,所以要初始化为node[i]=i,next=null

    for(int z=1; z<=arcnum1; z++)
    {
        scanf("%d%d",&i,&j);
        struct Node *temp = node[i].next;   //先存储当前next指针
        node[i].next = new Node();          //申请新的内存存储新的通路
        node[i].next->v = j;                //赋值
        node[i].next->next = temp;          //将以前的next域串在其后，连起来
        temp = node[j].next;                //因为无向图，所以不同起点操作一次，再以j为起点操作一次
        node[j].next = new Node();
        node[j].next->v = i;
        node[j].next->next = temp;
    }
}
//广度优先搜索
void bfs(int now)
{
    visited[now] = true;                               //将起始点标记为使用过
    que[++ que[0]] = now;                           //将队列初始化，把起始点加入进去
    while(que[0] != 0)
    {
        //如果队列中还有元素则继续
        now = que[que[0] --];                       //从队列取出元素，队列元素个数减一
        struct Node *temp = node[now].next;         //存储其next域
        while(temp != NULL)
        {
            //如果next域不为空，则表示还有和该点连通的点
            if(!visited[temp->v])
            {
                //如果该点未被使用则加入队列
                printf(" -> %d ", temp->v);
                visited[temp->v] = true;               //将加入的点标记为使用过
                que[++ que[0]] = temp->v;
            }
            temp = temp->next;                      //temp移向下一个next域
        }
    }
    return ;
}

void BFS1()
{
    memset(que, 0, sizeof(que));            //初始化que队列
    memset(visited, false, sizeof(visited));//初始化标记使用与否的数组visited
    printf("请输入顶点和边个数:\n");
    scanf("%d%d", &nodenum1,&arcnum1);                        //得到输入的顶点数
    printf("输入边数据:\n");
    BFSInitMap();                           //进入初始化函数
    for(int i = 1; i <= nodenum1; i ++)            //同样因为可能不连通需要多次进入
        if(!visited[i])
        {
            //如果未使用则进入bfs
            printf("从顶点%d开始遍历:\n", i);
            printf("%d", i);
            bfs(i);
            printf("\n");
        }
    system("pause");
    return ;
}




//初始化Map邻接矩阵
void DFSInitMap()
{
    int i,j;
    for(int p=1; p<=arcnum2; p++)
    {
        scanf("%d%d",&i,&j);
        Map[i][j] = true;
    }
}
//深度优先搜索
void dfs(int now)
{
    visited[now] = true;                       //进入后将当前节点标记为已使用
    for(int i = 1; i <= nodenum2; i ++)
        if(Map[now][i] && !visited[i])         //以当前节点为起始点寻找下一个未使用的节点
        {
            printf(" -> %d ", i);
            dfs(i);                         //找到后输出并以此节点进入dfs递归
        }
    return ;
}

void DFS1()
{
    char str1[10];
    memset(visited, false, sizeof(visited));
    printf("输入顶点和边的个数:\n");
    scanf("%d%d", &nodenum2,&arcnum2);
    printf("输入边的数据:\n");
    DFSInitMap();
    for(int i = 1; i <= nodenum2; i ++)
    {
        //如果图不连通，则需要多次调用
        if(!visited[i])                         //如果该节点未被使用则进入
        {
            printf("从顶点%d开始遍历:\n", i);
            printf("%d", i);
            dfs(i);
            printf("\n");
        }
    }
    system("pause");
    return ;
}




int main()
{
    int operation;
    while(true)
    {
        printf("*************************************\n");
        printf("   1.有向图邻接矩阵dfs递归遍历\n");
        printf("   2.无向图邻接表bfs非递归遍历\n");
        printf("   0.退出\n");
        printf("*************************************\n");
        scanf("%d", &operation);
        switch(operation)
        {
        case 1:
            DFS1();      //为1进入DFSMAIN
            break;
        case 2:
            BFS1();      //为2进入BFSMAIN
            break;
        case 0:
            return 0;       //为0退出程序
        default:
            printf("input error\n");
        }
        system("CLS");      //清除屏幕
    }
    return 0;
}

