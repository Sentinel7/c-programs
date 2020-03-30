#include <stdio.h>

int read_line(char output_array[], int size){
    int count = 0;
    char c;
    while (count < size) {
        scanf("%c", &c);
        if (c == '\n') {
            output_array[count] = '\0';
            return count;
        }
        output_array[count] = c;
        count++;
    }
    return count;
}

int main(){

    char the_line[1000];

    int num_read = 0;

    printf("Enter a line of input:\n");
    num_read = read_line(the_line, 1000);

    printf("Characters read: %d\n", num_read);
    printf("You entered: %s\n", the_line);

    printf("Enter another line (of at most 4 characters):\n");
    num_read = read_line(the_line, 5);

    printf("Characters read: %d\n", num_read);
    printf("You entered: %s\n", the_line);

    return 0;
}