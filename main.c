#include <stdio.h>
#include <stdlib.h>
#include "table.h"

void print_table(struct int_table_t* table){
    int i;
    for(i = 0; i < table->size; i++){
        if(table->used[i]){
            printf("%d ", table->data[i]);
        }else{
            printf("x ");
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    struct int_table_t* table;

    //Init a Table
    puts("Table created");
    table = create_int_table();

    //Insert 10 numbers, track the data
    puts("Instert 10 numbers");
    int_table_insert(table, 1);
    print_table(table);

    int_table_insert(table, 4);
    print_table(table);

    int_table_insert(table, 2);
    print_table(table);

    int_table_insert(table, 7);
    print_table(table);

    int_table_insert(table, 9);
    print_table(table);

    int_table_insert(table, 10);
    print_table(table);

    int_table_insert(table, 3);
    print_table(table);

    int_table_insert(table, 5);
    print_table(table);

    int_table_insert(table, 6);
    print_table(table);

    int_table_insert(table, 8);
    print_table(table);

    //Delete 6 elements by index
    puts("Remove 6 elements");
    int_table_delete(table, 0);
    print_table(table);

    int_table_delete(table, 2);
    print_table(table);

    int_table_delete(table, 4);
    print_table(table);

    int_table_delete(table, 6);
    print_table(table);

    int_table_delete(table, 8);
    print_table(table);

    int_table_delete(table, 1);
    print_table(table);

    //free the table
    puts("Freeing the table");
    delete_int_table(table);
    return 0;
}

