#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int x,y,z;
		for(x=0;x<=n/5;x++)
			for(y=0;y<=n/3;y++){
				z=100-x-y;
				if(5*x+3*y+z/3.0<=n)
					printf("x=%d,y=%d,z=%d\n",x,y,z);
			}
	}
	return 0;
}