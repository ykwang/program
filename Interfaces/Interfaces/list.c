#include<stdarg.h>
#include<stddef.h>
#include"assert.h"
#include"mem.h"
#include"list.h"

#define T List_T

T List_append(T list,T tail){
	T *p=&list;
	while(*p)
		p=&(*p)->rest;
	*p=tail;
	return list;
}
 T List_copy(T list){
	T head,*p=&head;
	while(list)
	{
		NEW(*p);
		(*p)->first=list->first;
		p=&(*p)->rest;
		list=list->rest;

	}
	*p=NULL;
	return head;
 }
T List_list(void *x,...){
	va_list ap;
	T list,*p=&list;

	va_start(ap,x);
	for(;x;x=va_arg(ap,void *)){
		NEW(*p);
		(*p)->first=x;
		p=&(*p)->rest;

	}
	*p=NULL;
	va_end(ap);
	return list;
}
T List_pop(T list,void **x){
	
	if(list){
		T head=list->rest;
		*x=list->first;
		FREE(list);
		return head;
	}
	else
		return list;

}
 T List_push(T list,void *x){
	T p;
	NEW(p);
	p->first=x;
	p->rest=list;
	return p;
 }
 T List_reverse(T list){
	T head=NULL,next;
	while(list){
	next=list->rest;
	list->rest=head;
	head=list;
	list=next;
	}
	return head;
 }
int List_length(T list){
	int i=0;
	while(list){
		i++;
		list=list->rest;
	}
	return i;
}
void List_free(T *list){
	T next;

	assert(list);
	while(*list){
		next=(*list)->rest;
		FREE(*list);
		*list=next;
	}
}
void List_map(T list,
	void apply(void **x,void *cl),void *cl){
	
		assert(apply);
		for(;list;list=list->rest)
			apply(&list->first,cl);
}
 void **List_toArray(T list,void *end){
	int i,n=List_length(list);
	void **arr=(void **)ALLOC((n+1)*sizeof(*arr));
	for(i=0;i<n;i++){
		arr[i]=list->first;
		list=list->rest;
	}
	arr[i]=end;
	return arr;
 }