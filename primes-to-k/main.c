#include <stdio.h>
#include <stdlib.h>

int is_prime(int n){
    for(int i = 2; i <= n-1; i++){
        if (n%i == 0)
            return 0;
    }
    return 1;
}

/* primes_up_to_k(k, size_ptr)
   Given an integer k, return an array of all
   prime numbers less than or equal to k.

   The provided int pointer size_ptr should be used
   as an output parameter to send back the size of the
   array.

   Task: Make this work properly.
*/
int* primes_up_to_k(int k, int* size_ptr) {
    int num_primes = 0;
    for (int i=2; i <= k; i++) {
        if (is_prime(i))
            num_primes++;
    }
    *size_ptr = num_primes;

    int* primes = malloc(num_primes * sizeof(int));
    int output_idx = 0;
    for (int i=0; i <= k; i++) {
        if (is_prime(i)) {
            primes[output_idx] = i;
            output_idx++;
        }
    }
    return primes;
}

int main() {

    int num_primes;
    int* primes = primes_up_to_k(50, &num_primes);

    printf("%d primes less than 50\n", num_primes);
    for(int i=0; i < num_primes; i++){
        printf("%d ", primes[i]);
    }

    free(primes);

    return 0;
}