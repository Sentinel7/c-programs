#include <stdio.h>

int main() {

    int tuna = 19;
    int *pTuna = &tuna; // &tuna gets the memory address of tuna

    printf("Address \t\t Name \t Value \n");
    printf("%p \t %s \t %d\n", pTuna, "tuna", tuna);
    printf("%p \t %s \t %p\n", &pTuna, "pTuna", pTuna);

    // *pTuna and tuna reference the same thing (Dereference pointer)
    printf("\n*pTuna: %d\n\n", *pTuna);


    int array[5] = {3, 19, 21, 7, 9};
    int *pa = array; // Points to first element of array

    for (int i=0; i < 5; i++) {
        // These two lines do the same thing
        printf("%p \t %d\n", &array[i], array[i]);
        printf("%p \t %d\n", pa+i, *(pa+i));
    }

    printf("%p \t %d\n\n", pa, *pa);


    // char[] and *char are both strings
    char movie1[] = "Hello World";
    char *movie2 = "Movie 2";
    movie2 = "New movie 2";

    puts(movie1);
    puts(movie2);
    printf("%s\n", movie2);

    return 0;
}
