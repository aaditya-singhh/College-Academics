// This program counts the number if inversions in two arrays using merge sort technique in time complexity of O(n log(n))

#include <stdio.h>
long merge(int arr[], int temp[], int left, int mid, int right)
{
   int i = left, j = mid + 1, k = left;
   long inversions = 0;


   while (i <= mid && j <= right)
   {
       if (arr[i] <= arr[j])
       {
           temp[k++] = arr[i++];
       }
       else
       {
           temp[k++] = arr[j++];
           inversions += (mid - i + 1);
       }
   }


   while (i <= mid)
   {
       temp[k++] = arr[i++];
   }


   while (j <= right)
   {
       temp[k++] = arr[j++];
   }


   for (i = left; i <= right; i++)
   {
       arr[i] = temp[i];
   }


   return inversions;
}


long mergeSort(int arr[], int temp[], int left, int right)
{
    long inv = 0;


   if (left < right)
   {
       int mid = left + (right - left) / 2;
       inv += mergeSort(arr, temp, left, mid);
       inv += mergeSort(arr, temp, mid + 1, right);
       inv += merge(arr, temp, left, mid, right);
   }


   return inv;
}


long nInversions(int arr[], int n)
{
   int temp[n];
   return mergeSort(arr, temp, 0, n - 1);
}


int main()
{
   int n;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);
   int arr[n];
   printf("\nEnter the elements of array (seperated by spcae): ");
   for (int i = 0; i < n; i++)
   {
       scanf("%d", &arr[i]);
   }


   long long inversions = nInversions(arr, n);
   printf("\nThe total number of inveresions are: %ld\n", inversions);


   return 0;
}
