#include<stdio.h>

void binarysearch(int arr[],int n,int data){
	int start=0;
	int end=n-1;
	while(start<=end){
	int mid=(start+end)/2;
	if(data==arr[mid]){
		printf("your element is in the index: %d",mid);
		return;
	}
	else if(data<arr[mid]){
		end=mid-1;
	}
	else{
		start=mid+1;
	}
}
	
}
int main(){
	int n;
	printf("enter the number of elements in array: ");
	scanf("%d",&n);
	
	int arr[n];
	
	printf("enter the elements in array (in sorted format ): ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int data;
	printf("enter the element you want to search in your array: ");
	scanf("%d",&data);
	binarysearch(arr,n,data);
	
	return 0;
}