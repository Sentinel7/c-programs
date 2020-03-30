/*  pi.c
    CSC 111 - Fall 2019 - Assignment 2

    B. Bird - 08/13/2019

    Jason Thomo - V00949336 - 08/17/2019
*/

#include <stdio.h>

double power(double base, int exp) {

    double result = base;
    for (int i=0; i < exp-1; i++) {
        result *= base;
    }
    return result;
}

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT rename the variables or move the declarations. */

    int n = 30; //Number of terms in summation

    /* END OF INPUT DATA */
    /* Implement your solution below this line */

    double pi = 0;
    for (int i=1; i <= n; i++)  {
        double term = ((4 * power(-1, i+1)) / ((2*i)-1)) * (power((1.0/2.0), ((2*i)-1)) + power((1.0/3.0), ((2*i)-1)));
        pi += term;
    }

    printf("With %d terms: pi = %.15f", n, pi);

    return 0;
}