#ifndef __TABLE_H__
#define __TABLE_H__

#include <stdlib.h>

struct int_table_t{
    int* data;
    int* used;
    int size;
    int num;
    int empty;
};

struct int_table_t* create_int_table(void);
void delete_int_table(struct int_table_t*);
int int_table_insert(struct int_table_t*, int);
void int_table_delete(struct int_table_t*, int);

#endif//__table_H__
