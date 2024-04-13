#include<bits/stdc++.h>
using namespace std;

int Largest(int arr[],int n){
    int max = arr[0];
    for (int i = 1; i < n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {1, 2, 3,7,54,23,2121};
    int  n = sizeof(arr)/sizeof(arr[0]);
    Largest(arr,n);
    cout << "The largest element is: "<< Largest(arr,n) ;   
    return 0;
}