#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    int i,j,temp=0;
    for( i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void display(int arr[],int n){
    cout<<"Sorted array will be:-"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[50],n;
    cout<<"Enter the size";
    cin>>n;
    cout<<"Enter the elements of array:-"<<endl;
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    bubbleSort(arr ,n);
    display(arr,n);
}
