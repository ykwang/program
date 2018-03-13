#ifndef ARRAYREP_INCLUDE
#define ARRAYREP_INCLUDE


#define T Array_T

struct T{
	int length;
	int size;
	char *arr;
};

extern void ArrayRep_init(T arr,int length,
	int size,void *ary);
#undef T

#endif