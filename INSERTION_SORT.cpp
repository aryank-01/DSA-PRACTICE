#include <stdio.h>

int main() {
	int n=5;
    int arr[5] = {3, 5, 6, 1, 7};

    for(int i = 1; i <= n-1; i++) {
        int key = arr[i];
        int j;
        for(int j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];   // shifting
        }
        arr[j + 1] = key;  // insert key
    }
    // Print array
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}