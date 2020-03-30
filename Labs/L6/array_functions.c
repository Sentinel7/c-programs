#include <stdio.h>

/* find_minimum_element( the_array, size )
   Given an array of the specified size, find and return
   the minimum element of the array.
*/
int find_minimum_element(int the_array[], int size){
    int min = the_array[0];
    for (int i=1; i < size; i++) {
        if (the_array[i] < min)
            min = the_array[i];
    }
    return min;
}

/* search_for_element( the_array, size, search_value )
   Given an array of the specified size, along with a value
   to search for, return 1 if the provided value is found
   somewhere in the array and 0 otherwise.
*/
int search_for_element(int the_array[], int size, int search_value){
    for (int i=0; i < size; i++) {
        if (the_array[i] == search_value)
            return 1;
    }
    return 0;
}

/* clamp( the_array, size, lower_bound, upper_bound )
   Given an array of the specified size, along with two
   bounds lower_bound and upper_bound, do the following:
    - Set any element with a value less than lower_bound to equal lower_bound
    - Set any element with a value greater than upper_bound to equal upper_bound
    - Leave all other elements intact.
   Note that the input array is modified by this function (and therefore, no
   return value is necessary).
*/
void clamp(int the_array[], int size, int lower_bound, int upper_bound ){
    for (int i=0; i < size; i++) {
        if (the_array[i] > upper_bound)
            the_array[i] = upper_bound;
        else if (the_array[i] < lower_bound)
            the_array[i] = lower_bound;
    }
}

/* print_array( the_array, size )
   Given an array of the specified size, print every element of the array,
   followed by a newline.
*/
void print_array( int the_array[], int size ){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", the_array[i]);
    }
    printf("\n");
}

/* Do not modify anything below here */
int main(){

    int A1[5] = {31, -41, 59, 2, 65};
    int A2[7] = {3, 58, 9, 79, 323, -8, 4};

    printf("A1 is ");
    print_array(A1,5);
    printf("A2 is ");
    print_array(A2,7);

    printf("Minimum element of A1: %d\n", find_minimum_element(A1, 5));
    printf("Minimum element of A2 (first four elements): %d\n", find_minimum_element(A2, 4));
    printf("Minimum element of A2 (all elements): %d\n", find_minimum_element(A2, 7));

    printf("Does A1 contain the element 2? search_for_element returns %d\n", search_for_element(A1, 5, 2));
    printf("Does A1 contain the element 6? search_for_element returns %d\n", search_for_element(A1, 5, 6));
    printf("Does A2 contain the element 6? search_for_element returns %d\n", search_for_element(A2, 7, 6));
    printf("Does A2 contain the element 4? search_for_element returns %d\n", search_for_element(A2, 7, 4));

    printf("Clamping A1 to the range [0, 50]\n");
    clamp(A1, 5, 0, 50);
    printf("A1 is ");
    print_array(A1,5);

    printf("Clamping A2 to the range [10, 100]\n");
    clamp(A2, 7, 10, 100);
    printf("A2 is ");
    print_array(A2,7);


    return 0;
}