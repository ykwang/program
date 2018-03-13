#include<stdlib.h>
#include"sort.h"
void swap(int*a,int *b){
	*a=*a^*b;
	*b=*a^*b;
	*a=*b^*a;
}
void insertSort(int *a,int len){
	int i,j;
	for(i=1;i<len;i++){
		for(j=i+1;j>=i;j--){
			if(a[j]<a[j-1]){
				swap(&a[j],&a[j-1]);
			}
		}
	}
}
void shell(int *a,int d,int len)
{
	int i,j;
	for(i=d;i<len;i++){
		int temp=a[i];
		for(j=i-d;j>=0&&a[j]>temp;j-=d)
			a[j+d]=a[j];
		if(j!=i-d)
			a[j+d]=temp;
	}
}
 void shellSort(int *a,int len)
 {
	 int d=len/2;
	 while(d>=1)
	 {
		 shell(a,d,len);
		 d=d/2;
	 }
 }
void selectSort(int *a,int len)
{
	int i,j,min;
	for(i=0;i<len;i++)
	{
		min=i;
		for(j=i+1;j<len;j++){
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i)
		swap(&a[i],&a[min]);
	}
}
 void bubbleSort(int *a,int len)
{
	int i,j;
	for(i=0;i<len;i++){
		for(j=len-1;j>i;j--){
			if(a[j]<a[j-1])
				swap(&a[j],&a[j-1]);
		}
	}
}
 int partition(int *a,int s,int e)
 {
	 int i,j;
	 for(i=s,j=i;i<e;i++)
		 if(a[i]<a[e]){
			swap(&a[j++],&a[i]);
		 }
		 swap(&a[j],&a[e]);
		 return j;
 }
 void quickSort(int *a,int start,int end)
 {
	 if(start<end){
		int q=partition(a,start,end);
		quickSort(a,start,q-1);
		quickSort(a,q+1,end);
	 }
 }
int Parent(int i){return i/2;}
int Left(int i){ return i*2;}
int Right(int i){return i*2+1;}
void MaxHeapIFY(int *a,int i,int len)
{
	int l=Left(i);
	int r=Right(i);
	int largest;
	if(l<len&&a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<len&&a[r]>a[largest])
		largest=r;
	if(largest!=i){
		swap(&a[i],&a[largest]);
		MaxHeapIFY(a,largest,len);
	}
}
void BuildMaxHeap(int*a,int len)
{
	int i;
	for(i=len/2;i>0;i--)
	{
		MaxHeapIFY(a,i,len);
	}
}
void heapSort(int *a,int len)
{
	BuildMaxHeap(a,len);
	int l=len;
	int i;
	for(i=len;i>1;i--){
		swap(&a[i],&a[l]);
		l--;
		MaxHeapIFY(a,1,len);
	}
}
void merge(int *a,int p,int q,int r)
{
	int n1=p-q+1;
	int n2=r-q;
	int *L=(int *)malloc(n1*sizeof(int));
	int *R=(int *)malloc(n2*sizeof(int));
	int i,j;
	for(i=0;i<n1;i++)
		L[i]=a[p+i-1];
	for(i=0;i<n2;i++)
		R[i]=a[q+i];
	i=j=0;
	int k;
	for(k=p;p<=r;p++)
		if(L[i]<=R[j])
			a[p]=L[i++];
		else
			a[p]=R[j++];
	free(L);
	free(R);
}
void mergeSort(int *a,int p,int r)
{
	if(p<r){
		int q=(p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a,p,q,r);
	}
}
