#include <stdio.h>
 #define MAXLENTH 50
 #define MAX 9999

void Dijkstra(int n, int v, int *dist, int *prev, int c[MAXLENTH][MAXLENTH])
{
 
   bool s[MAXLENTH];    
 int i,j;
    for(i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
  
        s[i] = false;    
        if(dist[i] == MAX)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = true;
 
   
    for(i=2; i<=n; ++i)
    {
        int t = MAX;
        int u = v;
       
        for(j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<t)
            {
               
                 u = j;            
                t = dist[j];
            }
   
        s[u] = true;    
 
       
        for(j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<MAX)
            {
                int newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}
 
void searchPath(int *prev,int v, int u)
{
    int que[MAXLENTH];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
   printf("%d -> ",que[i]);
        else
            printf("%d\n",que[i]);
}
 
int main()
{
    int dist[MAXLENTH];     // 表示当前点到源点的最短路径长度
    int prev[MAXLENTH];     // 记录当前点的前一个结点
    int c[MAXLENTH][MAXLENTH];   // 记录图的两点间路径长度
    int n, r;             // 图的结点数和路径数
 int p, q, len;          // 输入p, q两点及其路径长度
 int i,j;
 
    // 输入结点数
 printf("please input the num of the point:");
 scanf("%d",&n);
    // 输入路径数
 printf("please input the num of the edge:");
 scanf("%d",&r);
   
 
    // 初始化c[][]为MAX
    for(i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = MAX;
 
    for(i=1; i<=r; ++i) 
    {
        //printf("please input the value of the %dth edge:",i);
       scanf("%d %d %d",&p,&q,&len);

  
        if(len < c[p][q])      
        {
            c[p][q] = len;      // p指向q
            c[q][p] = len;      // q指向p，这样表示无向图
        }
    }
 
    for(i=1; i<=n; ++i)
        dist[i] = MAX;
  
    Dijkstra(n, 1, dist, prev, c);
 
     for(i=1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
            printf("%d ", c[i][j]);
        printf("\n");
    }
 
 printf("the shortest route length is :%d\n",dist[n]);
 
 printf("the first piont to the last point route:");
    searchPath(prev, 1, n);

}

