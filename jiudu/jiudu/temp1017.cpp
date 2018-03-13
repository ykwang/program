#include<stdio.h>
#include<stdlib.h>

int parent[100];
struct Edge{
	int start;
	int end;
	int weight;
}edge[10000];

int cmp(const void *a,const void *b){
	return ((struct Edge *)a)->weight-((struct Edge *)b)->weight;
}

int findroot(int x)
{
	if(parent[x]==-1)return x;
	else{
		int temp=findroot(parent[x]);
		parent[x]=temp;
		return temp;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int i,count,sum;
		sum=count=0;
		int m=n*(n-1)/2;
		for(i=0;i<=n;i++)parent[i]=-1;
		for(i=0;i<m;i++)
			scanf("%d %d %d",&edge[i].start,&edge[i].end,&edge[i].weight);
		qsort(edge,m,sizeof(edge[0]),cmp);
		for(i=0;i<m;i++){
			int a=findroot(edge[i].start);
			int b=findroot(edge[i].end);
			if(a!=b){
				parent[a]=b;
				sum+=edge[i].weight;
			}
		}
		printf("%d\n",sum);
		
	}
	return 0;
}