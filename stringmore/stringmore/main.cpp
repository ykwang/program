#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define N 4
char Strings[100][101];
char *ptr=NULL;

void ReverseString(char* s,int from,int to)
{
    while (from < to)
    {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void CreatString(char NewStr[][101])
{
	int i;
	for (i=1;i<N;i++){
		ReverseString(NewStr[i],0,i-1);
		ReverseString(NewStr[i],i,N-1);
		ReverseString(NewStr[i],0,N-1);
	}

}
char *max(char *str1,char *str2)
{
	int i;
	for(i=0;i<N;i++){
		if(str1[i]<str2[i])
			return str2;
		else if(str1[i]>str2[i])
			return str1;
		else
			i++;
	}
	if(i==N)
	return str2;
}
void SortString(char Strings[][101])
{
	int i,j;
	for(i=0;i<N-1;i++)
	{
		for (j=0;j<N-i-1;j++)
		{
			if(Strings[j]==max(Strings[j],Strings[j+1]))
            {int k;
			char c;
			for(k=0;k<N;k++){
				c=Strings[j][k];
				Strings[j][k]=Strings[j+1][k];
				Strings[j+1][k]=c;
			 }
			}
		}
	}
}
void findString(int SerialNumber,char *pOutString)
{
	int i;	

   CreatString(Strings);
   SortString(Strings);
   for(i=0;i<N;i++){
	   for(int j=0;j<N;j++)
		printf("%c",Strings[i][j]);
	    printf("\n");
   }
	for(i=0;i<N;i++)
	{
		pOutString[i]=Strings[SerialNumber-1][i];
	}
	pOutString[i]='\0';
	printf("%s",pOutString);
return;
}
void InputString(char *pInString)
{

	pInString=(char *)malloc(N*sizeof(char));
	int i;
	for(i=0;i<N;i++){
		scanf("%c",&pInString[i]);
	}
	pInString[i]='\0';	
	for(i=0;i<N;i++){
		int j;
		for(j=0;j<N;j++)
			Strings[i][j]=pInString[j];
		Strings[i][j]='\0';
	}

}
void Clear(void)
{
	free(ptr);
	free(Strings);
	return;
}
void main()
{
	char *pout=(char *)malloc(sizeof(char));
	InputString(ptr);
	findString(2,pout);
	
	return;
}