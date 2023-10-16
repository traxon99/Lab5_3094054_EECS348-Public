#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
// Function to read sales data from a file
void readSalesData(char filename[9], double sales[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        exit(1);
    }

    int month = 0;
    while (fscanf(file, "%lf", &sales[month]) != EOF && month < 12) {
        month++;
    }

    fclose(file);
}

// Function to print the sales report
void printSalesReport(double sales[]) {
    char months[12][20] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
    };
    printf("Monthly sales report for 2022:\n");
    printf("Month    Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
}

// Function to print the sales summary
void printSalesSummary(double sales[]) {
        char months[12][20] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
    };
    double minSales = sales[0];
    double maxSales = sales[0];
    double totalSales = 0.0;

    int minMonth = 0;
    int maxMonth = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] < minSales) {
            minSales = sales[i];
            minMonth = i;
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxMonth = i;
        }
        totalSales += sales[i];
    }

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, months[maxMonth]);
    printf("Average sales: $%.2f\n", totalSales / 12);
}

// Function to print six-month moving averages
void printMovingAverages(double sales[]) {
    printf("\nSix-Month Moving Average Report:\n");
    char months[7][30] = {"January - June", "February - July", "March - August", "April - September", "May - October", "June - November", "July - December"};
    
    for (int i = 0; i < 7; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s $%.2f\n", months[i], sum / 6);
    }
}

// Function to print the sales report sorted from highest to lowest
void printSortedSalesReport(double sales[]) {
    char months[12][20] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
    };
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month    Sales\n");

    // Create an array of structures to store month and sales data
    struct MonthSales {
        char *month;
        double sales;
    };
    struct MonthSales monthSales[12];

    for (int i = 0; i < 12; i++) {
        monthSales[i].month = months[i];
        monthSales[i].sales = sales[i];
    }

    // Sort the monthSales array based on sales in descending order
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (monthSales[j].sales > monthSales[i].sales) {
                struct MonthSales temp = monthSales[i];
                monthSales[i] = monthSales[j];
                monthSales[j] = temp;
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        printf("%s $%.2f\n", monthSales[i].month, monthSales[i].sales);
    }
}

int main() {
    double monthlySales[12];

    readSalesData("test.txt", monthlySales);
    printSalesReport(monthlySales);
    printSalesSummary(monthlySales);
    printMovingAverages(monthlySales);
    printSortedSalesReport(monthlySales);

    return 0;
}
