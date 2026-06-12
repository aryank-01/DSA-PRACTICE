#include<stdio.h>
int main(){
	int arr[4]={4,-6,2,8};
	int max=0;
	for(int i=0;i<4;i++){
		int sum=0;		
		for(int j=i;j<4;j++){
			sum=sum+arr[j];
			if(max<sum){
			max=sum;
		}	
        }
	}
	printf("%d",max);
	return 0;
}