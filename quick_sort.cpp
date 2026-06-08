#include <stdio.h>

// Partition function (pivot = first element)
int partition(int A[], int lb, int ub) {
    int pivot = A[lb];
    int start = lb;
    int end = ub;
    int temp;

    while (start < end) {

        // Move start forward
        while (A[start] <= pivot && start < ub)
            start++;

        // Move end backward
        while (A[end] > pivot)
            end--;

        // Swap if needed
        if (start < end) {
            temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }

    // Swap pivot with A[end]
    temp = A[lb];
    A[lb] = A[end];
    A[end] = temp;

    return end; // pivot position
}

// QuickSort function
void quickSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(A, lb, ub);

        quickSort(A, lb, loc - 1);
        quickSort(A, loc + 1, ub);
    }
}

// Print array
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    printArray(A, n);

    quickSort(A, 0, n - 1);

    printf("Sorted array:\n");
    printArray(A, n);

    return 0;
}