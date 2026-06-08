#include <stdio.h>

// heapify function : The process of rearranging a heap so that it satisfies the heap property.
void heapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp;

    if(left < n && A[left] > A[largest])
        largest = left;

    if(right < n && A[right] > A[largest])
        largest = right;

    if(largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}

// heap sort function
void heapSort(int A[], int n)
{
    // build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(A, n, i);

    // delete elements from heap
    for(int i = n-1; i > 0; i--)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapify(A, i, 0);
    }
}                                    
int main()
{
    int A[] = {4, 10, 3, 5, 1};
    int n = 5;
    int i;

    heapSort(A, n);

    printf("Sorted array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}