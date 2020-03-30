#include <stdio.h>
#include "table_library.h"

int main(){

    //t1 is a 4 x 3 table
    Table t1 = { {1,2,3},
                 {4,5,6},
                 {7,8,9},
                 {-6,1,0}
    };

    //t2 is a 2 x 5 table
    Table t2 = { {10, 20, 111, 116, 225},
                 {-370, -230, 0, 6, 10}
    };

    printf("Minimum element in t1: %d\n", find_minimum_element(t1, 4, 3) );
    printf("Minimum element in t2: %d\n", find_minimum_element(t2, 2, 5) );

    printf("Printing t1:\n");
    print_table(t1, 4, 3);

    printf("Printing t2:\n");
    print_table(t2, 2, 5);

    return 0;
}