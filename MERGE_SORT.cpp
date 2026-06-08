#include <stdio.h>
int n;
void merge(int arr[], int start, int mid, int end) {
   int temp[n];
   int i=start;
   int j=mid+1;
   int k=start; //to track temp array position
   while(i<=mid && j<=end){
   	    if(arr[i]<arr[j]){
   	  	    temp[k]=arr[i];
   	  	    i++;
		}
	    else{
	    	temp[k]=arr[j];
	    	j++;
		}
		k++;
   }
   while(i<=mid){
   	    temp[k]=arr[i];
   	    i++;
   	    k++;
   }
   while(j<=end){
   	    temp[k]=arr[j];
   	    j++;
   	    k++;
   }
   for(int i=start;i<=end;i++){
       arr[i]=temp[i];
   }
}

void mergesort(int arr[], int start, int end) {
   if(start<end){
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        
        merge(arr,start,mid,end);
   }
}

int main() {
	printf("enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
    for(int i=0;i<n;i++){
    	printf("\nenter the value of %d index: ",i);
    	scanf("%d",&arr[i]);
	}
    mergesort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
