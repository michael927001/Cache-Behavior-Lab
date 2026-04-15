#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1024

long long traverse_row_major(int matrix[SIZE][SIZE]) {
    long long sum = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

long long traverse_column_major(int matrix[SIZE][SIZE]) {
    long long sum = 0;

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int main() {
    static int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = 1;
        }
    }

    clock_t start, end;
    double row_time, col_time;
    long long sum;

    start = clock();
    sum = traverse_row_major(matrix);
    end = clock();
    row_time = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    sum = traverse_column_major(matrix);
    end = clock();
    col_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Row-major: %.6f seconds\n", row_time);
    printf("Column-major: %.6f seconds\n", col_time);

    return 0;
}