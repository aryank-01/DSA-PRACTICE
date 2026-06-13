#include<stdio.h>
int main(){
	int arr[8]={3,4,-2,5,8,20,-10,8};
	int totalsum=0;
	int sum=0;
	for(int i=0;i<8;i++){
		totalsum+=arr[i];
	}
	for(int i=0;i<8;i++){
		sum=sum+arr[i];
		if((totalsum-sum)==sum){
			printf("the index at which it can be divided into two parts is: %d",i);
		}
	}
}