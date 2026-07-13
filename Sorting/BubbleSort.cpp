#include <iostream>
using namespace std;
void BubbleSort(int arr[],int size){
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
}
void Display(int arr[], int size){
	for(int i=0; i<size;i++){
		cout<<arr[i]<<endl;
	}
}
int main(){
	int size;
	cout<<"Enter size of an array"<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter Values"<<endl;
	for(int i=0; i<size;i++){
		cin>>arr[i];
	}
	BubbleSort(arr,size);
	cout<<"After Sorted"<<endl;
	Display(arr,size);
}