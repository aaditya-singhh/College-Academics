#include <stdio.h>
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateArray(int arr[], int n, int d)
{
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array (each element separated by space):");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int d;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &d);
    rotateArray(arr, n, d);
    printf("Rotated array: ");
    printArray(arr, n);
    return 0;
}