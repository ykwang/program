#include<stddef.h>
#include"assert.h"
#include"mem.h"
#include"stack.h"

#define T Stack_T 

struct elem{
		void *x;
		struct elem *link;
	};
struct T{
	int count;
	struct elem *head;
};

 T Stack_new (void)
 {
	 T stk;
	 NEW(stk);
	 stk->count=0;
	 stk->head=NULL;
	 return stk;
	 
 }
 int Stack_emply(T stk){
	assert(stk);
	return stk->count==0;
 }

void Stack_push(T stk,void * x){
	struct elem *e;

	assert(stk);
	NEW(e);
	e->x=x;
	e->link=stk->head;
	stk->head=e;
	stk->count++;


}
void *Stack_pop(T stk){
	void *x;
	struct elem *e;

	assert(stk);
	assert(stk->count>0);
	e=stk->head;
	stk->head=e->link;
	x=e->x;
	stk->count--;
	FREE(e);
	return x;
}

 void Stack_free(T * stk){
	struct elem *e,*f;

	assert(stk&& (*stk));
	for(e=(*stk)->head;e;e=f){
		f=e->link;
		FREE(e);
	}
	FREE(*stk);
 }