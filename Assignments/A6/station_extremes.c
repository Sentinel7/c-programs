/*
   CSC 111 - Fall 2019 - Assignment 6

   Jason Thomo - V00949336
*/

#include <stdio.h>

int main() {

    double minTemps[1000];
    int minMonth[1000] = {0};
    int minDay[1000] = {0};
    int minHour[1000] = {0};
    int minMinute[1000] = {0};

    double maxTemps[1000];
    int maxMonth[1000] = {0};
    int maxDay[1000] = {0};
    int maxHour[1000] = {0};
    int maxMinute[1000] = {0};

    int numObservations[999] = {0};

    for (int i=0; i < 1000; i++) {
        minTemps[i] = 100;
        maxTemps[i] = -100;
    }

    FILE* input_file = fopen("input_data.txt", "r");

    int month, day, hour, minute, station;
    double temp;
    int line = 0;
    while (fscanf(input_file, "%d %d %d %d %d %lf", &month, &day, &hour, &minute, &station, &temp) == 6) {
        if (temp > maxTemps[station]) {
            maxTemps[station] = temp;
            maxMonth[station] = month;
            maxDay[station] = day;
            maxHour[station] = hour;
            maxMinute[station] = minute;
        }
        if (temp < minTemps[station]) {
            minTemps[station] = temp;
            minMonth[station] = month;
            minDay[station] = day;
            minHour[station] = hour;
            minMinute[station] = minute;
        }
        numObservations[station]++;
        line++;
    }

    FILE* output_file = fopen("station_extremes.txt", "w");
    for (int i=0; i < 1000; i++) {
        if (numObservations[i] > 0)
            fprintf(output_file, "Station %d: Minimum = %.2f degrees (%02d/%02d %02d:%02d), Maximum = %.2f degrees (%02d/%02d %02d:%02d)\n",
                    i, minTemps[i], minMonth[i], minDay[i], minHour[i], minMinute[i], maxTemps[i], maxMonth[i], maxDay[i], maxHour[i], maxMinute[i]);
    }
    fclose(output_file);

    fclose(input_file);

    return 0;
}