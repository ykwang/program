#include<stdio.h>
#include<string.h>

#define maxlen 109   
char x[maxlen],y[maxlen];
int b[maxlen][maxlen];
int c[maxlen][maxlen];

void LCSLength(char*X,char*Y,int m,int n,int c[][maxlen],int b[][maxlen])
{
	int i,j;
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++);
		c[0][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
				{
				c[i][j]=c[i][j-1];
				b[i][j]=-1;
			    }

		}
}

  int main()
{
        int m,n;
       while(scanf("%s",x)!=EOF&&scanf("%s",y)!=EOF){
        m=strlen(x);
        n=strlen(y);
        LCSLength(x,y,m,n,c,b);
        printf("%d\n",c[m][n]);
	   }
                return 0;
}