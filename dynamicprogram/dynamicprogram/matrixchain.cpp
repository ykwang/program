template<class T>
struct matrix{
	int m,n;
	T val[][];
};
struct matrix<int>*p;
void matrix_chain_order(struct matrix<int>*p)
{
	int n=20,i,j;
	int m[19][19];
	int s[19][19];
	for( i=0;i<20;i++)
		for(j=0;j<20;j++)
			m[i][j]=0;
	for(int l=2;l<20;l++)
		for(i=0;i<19;i++)
		{
			j=i+l-1;
			m[i][j]=32767;
			for(int k=i;k<j;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1].m*p[k].m*p[j].m;
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}

		}
}