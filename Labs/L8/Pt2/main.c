#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

/* read_point(f, pt)
   Given a file f (opened in mode "r") and a pointer pt to a Point object,
   attempt to read two double values from the file (using the '%lf' format specifier
   with fscanf) and set the x and y coordinates of pt to those values. If the values
   are read successfully, return 1. If fscanf is unable to read the values, return 0.
*/
int read_point(FILE* f, Point* pt){
    double x, y;
    if (fscanf(f, "%lf %lf", &x, &y) == 2) {
        pt->x = x;
        pt->y = y;
        return 1;
    }

    return 0;
}

int main(){
    /* Do not modify any code below this line (except the input file name if needed) */
    Point P;

    FILE* input_file = fopen("File3.txt","r");
    if (input_file == NULL){
        printf("Unable to open input file\n");
        return 1;
    }
    while( read_point(input_file, &P) != 0 ){
        double length = sqrt(P.x*P.x + P.y*P.y);
        printf("x = %f, y = %f, length = %f\n",P.x,P.y,length);
    }

    fclose(input_file);
    return 0;
}