#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<algorithm>
bool IsPalindrome(const char *s,int length)
{
	if(s==NULL||length<=1)
		return false;
	int start=0,end=length-1;
	while(start<end){
		if(s[start]!=s[end])
			return false;
		start++;
		end--;
	}
	return true;
}
int LongestPalindrome1(const char *s, int length){
	if(s==NULL||length<=1)
		return 0;
	int max=0;
	for(int i=1;i<length;++i){
		int j=i-1,k=i;
		while(j>=0&&k<length)
			if(s[j--]!=s[k++])
				break;				
		if(k-j+1>max)
			max=k-j+1;

		j=i-1;k=i+1;
		while(j>=0&&k<length)
			if(s[j--]!=s[k++])
				break;	
		if(k-j+1>max)
			max=k-j+1;
		
	}
	return max;
}
int LongestPalindrome2(const char *s, int length){
	char *S=(char *)malloc((2*length+1)*sizeof(char));
	int i;
	for( i=0;i<2*length+1;i++)
		if(i%2!=0)
			S[i]=s[i/2];
		else
			S[i]='#';
	S[i]='\0';
	int *p=(int *)malloc((2*length+1)*sizeof(char));
	int mx=0,id=0;
	memset(p,0,sizeof(p));
	for(i=1;S[i]!='\0';i++){
		p[i]=mx>i?p[2*id-i]>(mx-i)?p[2*id-i]:(mx-i):1;
		while(i+p[i]==i-p[i])
			p[i]++;
		if(i+p[i]>mx){
			mx=i+p[i];
			id=i;
		}
	}
	int max=0;
	while(p[i]!='\0')
		if(p[i]>max)
			max=p[i];
	return max;

}
