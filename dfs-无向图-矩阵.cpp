/*******************************************************************************************
¡¾DFS¡¿
Author:tmw
date:2018-2-19
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTEX 100
#define inf 65535  //±íÊ¾Á½µãÖ®¼äÃ»ÓÐ±ßÏàÁ¬

int visit[MAX_VERTEX];   //±ê¼Ç¶¥µãÊÇ·ñ±»·ÃÎÊ

/**Í¼µÄÁÚ½Ó¾ØÕóµÄ½¨Á¢**/
//ÁÚ½Ó¾ØÕóÊý¾Ý½á¹¹¶¨Òå
typedef struct Martrix_Graph
{
    char vertex[MAX_VERTEX]; //´æ´¢¶¥µãÐÅÏ¢
    int edge[MAX_VERTEX][MAX_VERTEX]; //´æ´¢±ßÐÅÏ¢
    int vertex_number,edge_number;//´æ´¢¶¥µãÊýºÍ±ßÊý
}Martrix_Graph;

void Create_non_direction_martrix_Graph( Martrix_Graph *G )
{
    int i,j,k,m;
    printf("ÇëÊäÈë¹¹ÔìµÄÎÞÏòÍ¼µÄ¶¥µãÊýºÍ±ßÊý£º\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("ÇëÊäÈëÎÞÏòÍ¼¶¥µãÐÅÏ¢£¨ÈçABCDEF....£©£º\n");
    char ch;
    while( ( ch = getchar() != '\n' ) );  //¹ýÂËµôÇ°ÃæµÄ\n£¬·ÀÖ¹\n±»scanf½øÈ¥
    for(i=0;i<G->vertex_number;i++)
        scanf("%c",&G->vertex[i]);

    //²»ÏàÁ¬µÄ¶¥µãÖ®¼äµÄÈ¨ÖµÉèÎªinf£¬°üÀ¨¶¥µã×ÔÉí
    //³õÊ¼»¯ÁÚ½Ó¾ØÕó
    for(i=0;i<G->vertex_number;i++)
        for(j=0;j<G->vertex_number;j++)
            G->edge[i][j] = inf;

    //¸üÐÂÎÞÏòÍ¼±ßÐÅÏ¢
    printf("ÇëÊäÈëÎÞÏòÍ¼ÁÚ½Ó¾ØÕóÏàÁ¬µÄ±ßÐÅÏ¢£¬ÏàÁ¬±ê¼ÇÎª1\n");
    for(k=0;k<G->edge_number;k++)
    {
        scanf("%d %d %d",&i,&j,&m);
        G->edge[i][j] = m;
        G->edge[j][i] = G->edge[i][j];//ÎÞÏòÍ¼ÊÇ¶Ô³ÆÕó
    }


    //´òÓ¡ÁÚ½Ó¾ØÕó´æ´¢ÐÅÏ¢£¬¼ì²éÕýÈ·ÐÔ
    printf("---------------------¹¹Ôì³öÀ´µÄÎÞÏòÍ¼ÁÚ½Ó¾ØÕóÈçÏÂ---------------------\n");
    for(i=0;i<G->vertex_number;i++)
    {
        for(j=0;j<G->vertex_number;j++)
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}

//´Óµ±Ç°µÚi¸ö¶¥µã³ö·¢£¬DFS±éÀú
void DFS(Martrix_Graph G, int i)
{
    int j;
    //±ê¼Çµ±Ç°¶¥µãÎªÒÑ·ÃÎÊ×´Ì¬
    visit[i] = true;
    printf("%c ",G.vertex[i]);

    //¶ÔÓë¸Ã¶¥µãÏàÁ¬µÄÆäËûÎ´·ÃÎÊ¶¥µã½øÐÐDFS
    for(j=0;j<G.vertex_number;j++)
    {
        if( G.edge[i][j]==1 && !visit[j] )
            DFS(G,j);
    }
}
//¶ÔÕû¸öÍ¼½øÐÐDFS
void DFS_Travel(Martrix_Graph G)
{
    //³õÊ¼»¯visitÊý×é
    int i;
    for(i=0;i<G.vertex_number;i++)
        visit[i] = false;

    //ÕûÕÅÍ¼µÄDFS
    printf("¶Ô¸ÃÎÞÏòÍ¼½øÐÐDFSµÄ½á¹ûÈçÏÂ£º\n");
    for(i=0;i<G.vertex_number;i++)
    {
        if( !visit[i] )
            DFS(G,i);
    }
}
int main()
{
    printf("²âÊÔ´úÂë\n");
    Martrix_Graph G;
    Create_non_direction_martrix_Graph(&G);
    DFS_Travel(G);
    return 0;
}
