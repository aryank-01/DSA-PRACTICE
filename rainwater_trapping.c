#include<stdio.h>
int rmax(int arr[],int index){
	int rmax=0;
	for(int i=index+1;i<6;i++){
		if(rmax<arr[i]){
			rmax=arr[i];
		}
	}
	return rmax;
}
int lmax(int arr[],int index){
	int lmax=0;
	for(int i=index-1;i>=0;i--){
		if(lmax<arr[i]){
			lmax=arr[i];
		}
	}
	return lmax;
}
int min(int a,int b){
	int sum=0;
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
int main(){
	int arr[6]={4,2,0,3,2,5};
	int sum=0;
	for(int i=1;i<5;i++){
		int x=min(rmax(arr,i),lmax(arr,i))-arr[i];
		if(x>0){
			sum=sum+x;
		}
	}
	printf("total water trapped: %d",sum,);
	return 0;
}