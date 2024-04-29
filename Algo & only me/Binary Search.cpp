#include<iostream>
using namespace std;

int Binary_search(int arr[], int n, int x) {
    int left=0,right=n-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        if(arr[mid]<x)
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;

}

int main()
{
    cout<< "Enter the size of array: ";
    int n;
    cin>> n;
    cout<< "input the elements of array: (It should be sorted....!)\n";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    cout<< "Enter the search element: ";
    int x;
    cin>>x;
    cout<< "Index: "<< Binary_search(arr,n,x)<< endl;
}
