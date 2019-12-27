#include <stdio.h>
#include <stdlib.h>

int* resize_array(int* original_array, int original_size, int new_size) {
    int* new_array = malloc(new_size * sizeof(int));
    for (int i=0; i < original_size; i++) {
        new_array[i] = original_array[i];
    }
    free(original_array);
    return new_array;
}

int main() {

    int* array = malloc(5 * sizeof(int));
    int current_size = 0;
    int max_size = 5;

    int val;
    printf("Enter some numbers. Enter a non-numerical value when finished.\n");
    while(scanf("%d", &val) == 1){
        if (current_size < max_size){
            array[current_size] = val;
            current_size++;
        } else {
            //array is full, resize (add 5 more empty elements)
            array = resize_array(array, max_size, max_size + 5);
            max_size += 5;
            array[current_size] = val;
            current_size++;
        }
    }

    for (int i=0; i < current_size; i++){
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}