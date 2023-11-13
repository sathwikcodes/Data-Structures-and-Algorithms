#include<iostream>
using namespace std;

void LeftRotate(int arr[], int n){
    int temp = arr[0];
    for (int i = 1; i < n; i++){
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {5,30,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    LeftRotate(arr, n);
    return 0;
}