/* tuition.c
   CSC 111 - Fall 2019 - Assignment 1

   B. Bird - 08/13/2019

   Jason Thomo - V00949336 - 08/10/2019
*/

#include <stdio.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT rename the variables or move the declarations. */

    double specialized_engineering_units = 1.5;
    double normal_units = 7.5;

    double cost_per_specialized_engineering_unit = 1793.01111;
    double cost_per_normal_unit = 1661.73;

    /* END OF INPUT DATA */
    /* Implement your solution below this line */

    double total_cost_specialized_engineering = (specialized_engineering_units * cost_per_specialized_engineering_unit);
    printf("Specialized Engineering units: %.1f, Cost per unit: $%.2f, Total cost: $%.2f \n", specialized_engineering_units, cost_per_specialized_engineering_unit, total_cost_specialized_engineering);

    double total_cost_normal = (normal_units * cost_per_normal_unit);
    printf("Normal units: %.1f, Cost per unit: $%.2f, Total cost: $%.2f \n", normal_units, cost_per_normal_unit, total_cost_normal);

    double total_units = (specialized_engineering_units + normal_units);
    double total_tuition = (total_cost_normal + total_cost_specialized_engineering);
    printf("Total units: %.1f, Total tuition: $%.2f \n", total_units, total_tuition);

    return 0;
}