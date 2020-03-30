/*
   CSC 111 - Fall 2019 - Assignment 6

   Jason Thomo - V00949336
*/

#include <stdio.h>

int main() {

    double minTemps[13][32];
    double maxTemps[13][32];
    int numObservations[13][32] = {0};

    for (int i=0; i < 13; i++) {
        for (int j=0; j < 32; j++) {
            minTemps[i][j] = 100;
            maxTemps[i][j] = -100;
        }
    }

    FILE* input_file = fopen("input_data.txt", "r");

    int month, day, hour, minute, station;
    double temp;
    int line = 0;
    while (fscanf(input_file, "%d %d %d %d %d %lf", &month, &day, &hour, &minute, &station, &temp) == 6) {
        if (temp > maxTemps[month][day])
            maxTemps[month][day] = temp;
        if (temp < minTemps[month][day])
            minTemps[month][day] = temp;
        numObservations[month][day]++;
        line++;
    }

    FILE* output_file = fopen("daily_minimum_maximum_summary.txt", "w");
    for (int i=0; i < 13; i++) {
        for (int j=0; j < 32; j++) {
            if (numObservations[i][j] > 0)
                fprintf(output_file, "%d %d %.2lf %.2lf\n", i, j, minTemps[i][j], maxTemps[i][j]);
        }
    }
    fclose(output_file);

    fclose(input_file);

    return 0;
}