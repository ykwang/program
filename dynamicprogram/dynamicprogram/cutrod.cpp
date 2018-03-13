#include<stdio.h>
#define max(m,n) m>=n?m:n;
int cut_rod(int p[],int n)
{
	if(n==0)
		return 0;
	int q=-1;
	for(int i=1;i<=n;i++)
	{
		q=max(q,p[i]+cut_rod(p,n-i));
	}
	return q;
}
int * bottom_up_cut_rod(int p[],int n)
{
	int r[20];
	int q;
	r[0]=0;
	for(int i=1;i<=n;i++)
	{
		q=-1;
		for(int j=1;j<=i;j++){
			q=max(q,p[j]+r[i-j]);
			}
		r[i]=q;
	}
	return r;
}
int memoized_cut_rod_aux(int p[],int n,int r[])
{
	int q;
	if(r[n]>=0)
		return r[n];
	if(n==0)
		q=0;
	else
	{
		q=-1;
		for(int i=1;i<=n;i++)
		{
			q=max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
		}
	}
	r[n]=q;
	return q;
}

