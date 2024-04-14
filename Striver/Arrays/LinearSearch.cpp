#include<bits/stdc++.h>
using namespace std;

int Search(int arr[], int n, int k){
    for (int i = 0; i < n;i++){
        if(arr[i] == k){
            return 1;
        }
        }
    return -1;
}

int main(){
    int arr[] = {1, 24, 5, 5, 66, 7, 8, 43, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << Search(arr, n, 78);
    return 0;
}