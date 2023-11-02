#include <stdio.h>
void rotateMatrix(int mat[][3], int N)
{
    int temp[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            temp[j][N - i - 1] = mat[i][j];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat[i][j] = temp[i][j];
        }
    }
}
void printMatrix(int mat[][3], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int N = 3;
    int mat[N][N];
    printf("Enter the elements of the matrix (each element separated byspace) :\n ");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int degrees;
    printf("Enter the degrees to rotate (90, 180, 270, or 360): ");
    scanf("%d", &degrees);
    int rotations = degrees / 90;
    for (int i = 0; i < rotations; i++)
    {
        rotateMatrix(mat, N);
    }
    printf("Rotated matrix:\n");
    printMatrix(mat, N);
    return 0;
}