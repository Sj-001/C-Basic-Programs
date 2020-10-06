#include<iostream>
using namespace std;
void display(int arr[], int n){
	cout<<"sorted array:-"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void swap(int *a, int *b){
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}
void selectionSort(int arr[], int n){
	int i,j, min=0,temp=0;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++)
			if(arr[min]>arr[j])
				min=j;
		swap(&arr[min],&arr[i]);
	}
}
int main(){
	int arr[50],n;
	cout<<"Enter the size of array:-"<<endl;
	cin>>n;
	cout<<"Enter the elements of array:-"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selectionSort(arr,n);
	display(arr,n);
}
