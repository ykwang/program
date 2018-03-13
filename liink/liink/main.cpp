

#include"list.h"

int main()
{
	List<int> ls,ll;

	int b;
	int a[10]={12,41,54,1,5,7,89,4,6,42};
	for(int i=0;i<10;i++){
		ls.List_push(a[i]);
	}
	ll=ls;
	ls.List_reverse();
	ll.List_pop(b);
	std::cout<<b;
	return 1;
}