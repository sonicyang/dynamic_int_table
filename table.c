#include <stdlib.h>
#include <string.h>

#include "table.h"

struct int_table_t* create_int_table(){
    struct int_table_t* int_table = (struct int_table_t*)malloc(sizeof(struct int_table_t));
    int i;

    int_table->size = 0;
    int_table->num = 0;
    int_table->empty = -1;

    int_table->data = NULL;

    return int_table;
}

void delete_int_table(struct int_table_t* int_table){
    if(int_table->size){
        free(int_table->data);
    }

    free(int_table);
    return;
}

int int_table_insert(struct int_table_t* int_table, int x){
    int* ptr;
    int* ptr2;
    int i = 0;

    if(int_table == NULL)
        return -1;

    if(int_table->size == 0){
        int_table->data = malloc(sizeof(int));
        int_table->used = malloc(sizeof(int));
        memset(int_table->used, 0, sizeof(int));
        int_table->size = 1;
        int_table->empty = 0;
    }
    if(int_table->num == int_table->size){
        ptr = int_table->data;
        ptr2 = int_table->used;

        int_table->data = malloc(sizeof(int) * int_table->size * 2);
        int_table->used = malloc(sizeof(int) * int_table->size * 2);
        memset(int_table->used, 0, sizeof(int) * int_table->size * 2);
        memcpy(int_table->data, ptr, sizeof(int) * int_table->size);
        memcpy(int_table->used, ptr2, sizeof(int) * int_table->size);

        free(ptr);
        free(ptr2);

        int_table->empty = int_table->size;

        for(i = 0; i < int_table->size - 1; i++)
            int_table->data[i + int_table->size] = i + int_table->size + 1;

        int_table->data[int_table->size * 2 - 1] = -1;

        int_table->size = int_table->size * 2;
    }

    i = int_table->empty;
    int_table->empty = int_table->data[i];

    int_table->data[i] = x;
    int_table->used[i] = 1;
    int_table->num++;
    return i;
}

void int_table_delete(struct int_table_t* int_table, int x){
    int* ptr;
    int* ptr2;
    int i, k;

    if(int_table == NULL)
        return;

    if(x < 0 || x > int_table->size - 1)
        return;

    int_table->data[x] = 0;
    int_table->used[x] = 0;
    int_table->num--;

    if(4 * int_table->num == int_table->size){
        ptr = int_table->data;
        ptr2 = int_table->used;

        int_table->data = malloc(sizeof(int) * int_table->size / 2);
        int_table->used = malloc(sizeof(int) * int_table->size / 2);
        memset(int_table->used, 0, sizeof(int) * int_table->size / 2);

        k = 0;
        for(i = 0; i < int_table->size; i++){
            if(ptr2[i]){
                int_table->data[k] = ptr[i];
                int_table->used[k++] = ptr2[i];
            }
        }

        int_table->empty = k;

        for(; k < int_table->size - 1; k++){
            int_table->data[k] = k + 1;
        }
        int_table->data[k] = -1;

        free(ptr);
        free(ptr2);

        int_table->size = int_table->size / 2;
    }
    return;
}
