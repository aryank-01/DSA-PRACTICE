#include<stdio.h>
int main(){
	int n;
	printf("enter the number of elements of your array : ");
	scanf("%d",&n);
	int arr[n];
	printf("\n enter the numbers");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<=n-2;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}	
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
