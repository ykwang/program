#include<stdio.h>

int main()
{
	char s[100],c;
	while(scanf("%s",s)!=EOF){
		getchar();
		scanf("%c",&c);
		char *p=s;
		while(*p!='\0'){
			if(*p==c){
				char *q=p;
				while(*q!='\0'){
					*q=*(q+1);
					q++;
				}
				*q='\0';
			}
			if(*p!=c)
			p++;
		}
		*p='\0';
		printf("%s\n",s);
	
	}
	return 0;
}