#undef assert
#ifdef NDEBUG
#define assert(e) ((viod)0)
#else
#include"except.h"
extern void assert(int e);
#define assert(e) ((void)((e)||(RAISE(Assert_Failed),0)))
#endif