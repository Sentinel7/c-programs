#include <stdio.h>
#include "table_library.h"

/* find_minimum_element( T, rows, cols )
   Given a table T with the provided number of rows and columns,
   find and return the minimum element of T.
*/
int find_minimum_element(Table T, int rows, int cols){
    int min = 1000000;
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            if (T[i][j] < min)
                min = T[i][j];
        }
    }
    return min;
}

/* print_table( T, rows, cols )
   Given a table T with the provided number of rows and columns,
   print each element of T, with one row per line.
*/
void print_table( Table T, int rows, int cols ) {
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
}