// Two sum problem using merge sort adn binary search to achieve a time complexity of o(n log n)



#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int hasPairWithSum(int arr[], int n, int X) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == X) {
            return 1;
        } else if (sum < X) {
            left++;
        } else {
            right--;
        }
    }
    return 0;
}

int main() {
    int n, X;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum (X): ");
    scanf("%d", &X);

    // Sorting the array
    mergeSort(arr, 0, n - 1);

    if (hasPairWithSum(arr, n, X)) {
        printf("There exist two integers in the array whose sum is %d.\n", X);
    } else {
        printf("No such pair found in the array.\n");
    }

    return 0;
}
