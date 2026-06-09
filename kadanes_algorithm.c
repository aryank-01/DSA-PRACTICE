#include <stdio.h>
int main() {
    int arr[5] = {4, -6,-1, 2, 8};
    int max = arr[0];
    int current=arr[0];

    for (int i = 1; i < 5; i++) {
        if(current<0){
        	current=arr[i]; //start a new subarray
		}
		else{
			current=current+arr[i];
		}
		if(current>max){
			max=current;
		}
    }

    printf("%d", max);
    return 0;
}
