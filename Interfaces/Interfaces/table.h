#ifndef TABLE_INCLUDE
#define TABLE_INCLUDE

#define T Table_T
typedef struct T *T;

extern T Table_new(int hint,
	int cmp(const void *x,const void *y),
	unsigned hash(const void *key));
extern void Table_free(T *table);
extern int Table_length(T table);
extern void *Table_put(T table,const void *key,
	void *value);
extern void *Table_get(T table,const void *key);
extern void *Table_remove(T table,const void *key);


#undef T
#endif