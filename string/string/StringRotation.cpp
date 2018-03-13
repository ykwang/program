#include<stdio.h>
void LeftShiftOne(char *s,int n){
	char t=s[0];
	for(int i=1;i<n;i++){
		s[i-1]=s[i];
	}
	s[n-1]=t;
}

void LeftRotationString(char *s,int n,int m){
	while(m--)
		LeftShiftOne(s,n);
}

void reverse(char *from,char *to)
{
	if(*from==NULL||*to==NULL)
		return;
	char c;
	while(from<to){
		c=*from;
		*from=*to;
		*to=c;
		from++;
		to--;
	}
}

void LeftRotationString(char *s,char *end,char *to){
	reverse(s,    to);
	reverse(to+1,end);
	reverse(s,   end);
}

bool CalcAllPermutation(char* perm, int num){
	
	int i;
	for(i=num-2;i>=0&&perm[i]>=perm[i+1];--i)
		;
	if(i<0)
		return false;
	int k;
	for(k=num-1;k>i&&perm[k]<=perm[i];k--)
		;
	char c=perm[k];
	perm[k]=perm[i];
	perm[i]=c;
	reverse(perm+i+1,perm+num);
	return true;
}