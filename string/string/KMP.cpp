#include<string>
#include<iostream>
using namespace std;
int *ComputePrefix(string p){
	int m=p.length();
	int *w=new int[m+1];
	w[1]=w[0]=0;
	int k=0;
	for(int q=2;q<m;q++){
		while(k>0&&p[k]!=p[q-1])
			k=w[k];
		if(p[k]==p[q-1])
			k++;
		w[q]=k;
	}
	return w;
}
void kmp_match(string &t,string &p){
	int n=t.length();
	int m=p.length();
	int *w=ComputePrefix(p);
	int q=0;
	for(int i=0;i<n;i++){
		while(q>0&&p[q]!=t[i])
			q=w[q-1];
		if(p[q]==t[i])
			q=q+1;
		if(q==m)
			cout<<"match from i-m+1";
		q=w[q-1];
	}
}