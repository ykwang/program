#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include"assert.h"
#include"array.h"
#include"arrayrep.h"
#include"mem.h"
#include"seq.h"

#define T Seq_T

struct T{
	struct Array_T arr;
	int length;
	int head;
};
static void expand(T seq){
	int n=seq->arr.length;
	Array_resize(&seq->arr,2*n);
	if(seq->head>0){
		void **old=&((void **)seq->arr.arr)[seq->head];
		memcpy(old+n,old,(n-seq->head)*sizeof(void *));
		seq->head+=n;
	}
}

T Seq_new(int hint){
	T seq;
	
	assert(hint>=0);
	NEW0(seq);
	if(hint==0)
		hint=16;
	ArrayRep_init(&seq->arr,hint,sizeof(void *),
		ALLOC(hint*sizeof(void *)));
	return seq;
}

T Seq_seq(void *x,...){
	va_list ap;
	T seq=Seq_new(0);
	va_start(ap,x);
	for(;x;x=va_arg(ap,void*))
		Seq_addhi(seq,x);
	va_end(ap);
	return seq;
}
 void Seq_free(T *seq){
	assert(seq&&*seq);
	assert((void *)*seq==(void *)&(*seq)->arr);
	Array_free((Array_T *)seq);
 }
 int Seq_length(T seq){
	assert(seq);
	return seq->length;
 }
 void *Seq_get(T seq,int i){
	assert(seq);
	assert(i>=0&&i<seq->length);
	return ((void **)seq->arr.arr)[
		(seq->head+i)%seq->arr.length];
 }
void *Seq_put(T seq,int i,void *x){
	void *prev;

	assert(seq);
	assert(i>=0&&i<seq->length);
	prev=((void **)seq->arr.arr)[
		(seq->head+i)%seq->arr.length];
	((void **)seq->arr.arr)[
		(seq->head+i)%seq->arr.length]=x;
	return prev;

}
void *Seq_addlo(T seq,void *x){
	int i=0;
	assert(seq);
	if(seq->length==seq->arr.length)
		expand(seq);
	if(--seq->head<0)
		seq->head=seq->arr.length-1;
	seq->length++;
	return ((void **)seq->arr.arr)[
		(seq->head+i)%seq->arr.length]=x;
}
 void *Seq_addhi(T seq,void *x){
	int i;
	assert(seq);
	if(seq->length==seq->arr.length)
		expand(seq);
	i=seq->length++;
	return ((void **)seq->arr.arr)[
		(seq->head+i)%seq->arr.length]=x;
 }
 void *Seq_remlo(T seq){
	int i=0;
	void *x;

	assert(seq);
	assert(seq->length>0);
	x=((void **)seq->arr.arr)[
		(seq->head+i)%seq->arr.length];
	seq->head=(seq->head+1)%seq->arr.length;
	--seq->length;
	return x;
 }
void *Seq_remhi(T seq){
	int i;

	assert(seq);
	assert(seq->length>0);
	i=--seq->length;
	return ((void **)seq->arr.arr)[
		(seq->head+i)%seq->arr.length];
}