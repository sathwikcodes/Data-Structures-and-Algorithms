#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n){
    int temp[n];
    for (int i = 1; i < n; i++){
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

void rotateOptimal(int arr[], int n){
    int temp = arr[0];

    for (int i = 0; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[n - 1] =  temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 5, 43, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    rotateOptimal(arr, n);
    return 0;
}