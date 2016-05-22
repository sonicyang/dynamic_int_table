Dynamic Table
=============

This is an implementation of dynamic table of integer type.
The table will grow 2x up on size limit reached, and will contract 1/2x upon element only occupy 1/4 of its size.

Usage
-----

To use this library, you should include table.h.

#include "table.h"

This library support 4 functions
 - create_int_table
 - delete_int_table
 - int_table_insert
 - int_table_delete

The type of dynamic table is 
 - sturct int_table_t

You must first declare and create a table

`struct int_table_t* table = create_int_table()`

Then you can insert a integer x

`int_table_insert(table, x)`

Or you can remove a element by index i

`int_table_delete(table, i)`

To access the data array

`table->data`

if a valid data is present in the ith slot

`table->used[i]` would be 1, otherwise 0.

Don't forget to free the table after use.

`delete_int_table(table)`

Example
-------
A example program is included as main.c. 

Please compile it with table.c.
