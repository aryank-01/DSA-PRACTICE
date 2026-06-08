#include<stdio.h>
int main(){
	int n=6;
	int arr[n]={3,2,1,6,8,4};
	for(int i=0;i<=n-2;i++){
		int min=i;
		for(int j=i+1;j<=n-1;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}