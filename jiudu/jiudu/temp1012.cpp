#include<stdio.h>

int parent[1000];
int findroot(int x){
	if(parent[x]==-1)return x;
	else
	{
		int temp=findroot(parent[x]);
		parent[x]=temp;
		return temp;
	}
}

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0)break;
		int i,a,b,count=0;
		for(i=0;i<=n;i++)parent[i]=-1;
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			int pa=findroot(a);
			int pb=findroot(b);
			if(pa!=pb)
				parent[pa]=b;
		}
		for(i=1;i<=n;i++)
			if(parent[i]==-1)count++;
		printf("%d\n",count-1);

	}
}