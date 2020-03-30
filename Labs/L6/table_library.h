typedef int Table[100][100];

/* find_minimum_element( T, rows, cols )
   Given a table T with the provided number of rows and columns,
   find and return the minimum element of T.
*/
int find_minimum_element( Table T, int rows, int cols );

/* print_table( T, rows, cols )
   Given a table T with the provided number of rows and columns,
   print each element of T, with one row per line.
*/
void print_table( Table T, int rows, int cols );