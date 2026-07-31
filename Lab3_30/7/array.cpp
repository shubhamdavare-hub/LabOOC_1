#include<iostream>
using namespace std;

int main()
{
    int *arr;
    int size,sum=0;

    cout<<"Enter the size of the integer array:";
    cin>>size;
    
    arr= new int[size];
    cout<<"Creating an array of size"<<size<<"..";
   
    
    for(int i=0;i<size;i++){
        cout<<"Enter element : ";
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<"nsum of all elements = "<<sum<<endl;
    delete arr;
    return 0;
    
}