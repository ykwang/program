#include<stdlib.h>
#include<string.h>
#include"assert.h"
#include"except.h"
#include"arena.h"

#define T Arena_T

const Except_T Arena_NewFailed=
{"Arena Creation Failed"};
const Except_T Arena_Failed=
{"Arena Allocation Failed"};

#define THRESHOLD 10

union align{
	int i;
	long l;
	long *lp;
	void *p;
	void(*fp)(void);
	float f;
	double d;
	long double ld;
};
union header {
	struct T b;
	union align a;
};
static T freechunks;
static int nfree;
T Arena_new(void){
	T arena=(struct T *)malloc(sizeof(*arena));
	if(arena==NULL)
		RAISE(Arena_NewFailed);
	arena->prev=NULL;
	arena->avail=arena->limits=NULL;
	return arena;
}

void Arena_dispose(T *ap){
	assert(ap&&*ap);
	Arena_free(*ap);
	free(*ap);
	*ap=NULL;
}

 void *Arena_alloc(T arena,long nbytes,
	const char *file,int line){
	assert(arena);
	assert(nbytes>0);

	nbytes=((nbytes+sizeof(union align)-1)/
		(sizeof(union align)))*(sizeof(union align));
	while(nbytes>arena->limits-arena->avail){
		T ptr;
		char *limits;
		if((ptr=freechunks)!=NULL){
			freechunks=freechunks->prev;
			nfree--;
			limits=ptr->limits;
		}
		else{
			long m=sizeof(union header)+nbytes+10*1024;
			ptr=(struct T *)malloc(m);
			if(ptr==NULL)
			{
				if(file==NULL)
					RAISE(Arena_Failed);
				else
					Except_raise(&Arena_Failed,file,line);
			}
			limits=(char *)ptr+m;
		}
		*ptr=*arena;
		arena->avail=(char *)((union header *)ptr+1);
		arena->limits=limits;
		arena->prev=ptr;

	}
	arena->avail+=nbytes;
	return arena->avail-nbytes;
 }
 void *Arena_calloc(T arena,long count,
	long nbytes,const char *file,int line){
	void *ptr;
	
	assert(count>0);
	ptr=Arena_alloc(arena,count*nbytes,file,line);
	memset(ptr,'\0',count*nbytes);
	return ptr;
 }
 void Arena_free(T arena){
	assert(arena);
	while(arena->prev){
		struct T tmp=*arena->prev;
		if(nfree<THRESHOLD){
			arena->prev->prev=freechunks;
			freechunks=arena->prev;
			nfree++;
			freechunks->limits=arena->limits;
		}
		else
			free(arena->prev);
		*arena=tmp;
	}
	assert(arena->limits==NULL);
	assert(arena->avail==NULL);
 }