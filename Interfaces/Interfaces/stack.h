#ifndef STACK_INCLUDE
#define STACK_INCLUDE

#define  T Stack_T
typedef struct T * T;

extern T Stack_new (void);
extern int Stack_emply(T stk);
extern void Stack_push(T stk,void * x);
extern void *Stack_pop(T stk);
extern void Stack_free(T * stk);


#undef T
#endif