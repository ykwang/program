#include<stdio.h>
#include<stdlib.h>
int main()
{
	int k;
	while(scanf("%d",&k)!=EOF){
		
		int *inter=(int *)malloc(k*sizeof(int));
		int i;
		for(i=0;i<k;i++){
			scanf("%d",&inter[i]);
		}
		if(k==0){
			printf("%d %d %d\n",0,0,0);
			continue;
		}
		for(i=0;i<k;i++){
			if(inter[i]>0)
				break;
		}
		if(i>=k){
			printf("%d %d %d\n",0,inter[0],inter[i-1]);
			continue;
		}
		int len,j,m,p,l,max;
		m=0;
		max=-32767;
		
		for(len=1;len<=k;len++){
			for(j=0;j<k;j++){
				i=0;
				while(i<len){
					if(j+i>=k)break;
					m+=inter[j+i];
					i++;
				}
				
				if(i>=len&&((max==m&&p>j)||max<m)){
					max=m;
					p=j;
					l=len;
				}
				m=0;
			}
		}
		printf("%d %d %d\n",max,inter[p],inter[p+l-1]);
		free(inter);
		inter=NULL;
	}
	return 0;
}