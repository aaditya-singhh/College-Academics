#include <stdio.h>

#define N 3

void rotateClockwise(int mat[N][N]) {
    for (int i = 0; i < N / 2; ++i) {
        for (int j = i; j < N - i - 1; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = temp;
        }
    }
}

void printArray(int mat[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[N][N] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    printf("Original array:\n");
    printArray(mat);

    rotateClockwise(mat);

    printf("\nRotated array (clockwise):\n");
    printArray(mat);

    return 0;
}
