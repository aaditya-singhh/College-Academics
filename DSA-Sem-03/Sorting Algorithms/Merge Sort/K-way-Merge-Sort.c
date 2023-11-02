// Implemented the k-way merging, where k > 2. 
// The input to the function will be the value of k and k is the number of sorted arrays.
// The output will be the sorted array.



#include <stdio.h>

void mergeArrays(int arr1[], int l1, int arr2[], int l2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < l1 && j < l2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < l1) {
        result[k++] = arr1[i++];
    }

    while (j < l2) {
        result[k++] = arr2[j++];
    }
}

void kWayMerge(int arrays[][100], int k, int lengths[], int result[]) {
    int tempLength = lengths[0];
    int tempArray[100];

    for (int i = 0; i < tempLength; i++) {
        tempArray[i] = arrays[0][i];
    }

    for (int i = 1; i < k; i++) {
        mergeArrays(tempArray, tempLength, arrays[i], lengths[i], result);
        tempLength += lengths[i];

        for (int j = 0; j < tempLength; j++) {
            tempArray[j] = result[j];
        }
    }

    for (int i = 0; i < tempLength; i++) {
        result[i] = tempArray[i];
    }
}

int main() {
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k <= 2) {
        printf("k must be greater than 2.\n");
        return 1;
    }

    int arrays[k][100];
    int lengths[k];

    for (int i = 0; i < k; i++) {
        int n;
        printf("Enter the length of array %d: ", i + 1);
        scanf("%d", &n);

        lengths[i] = n;

        printf("Enter the sorted elements of array %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    int totalLength = 0;
    for (int i = 0; i < k; i++) {
        totalLength += lengths[i];
    }

    int result[totalLength];
    kWayMerge(arrays, k, lengths, result);

    printf("Sorted Array: ");
    for (int i = 0; i < totalLength; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}