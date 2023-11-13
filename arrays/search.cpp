#include<iostream>
using namespace std;

int search(int arr[], int n, int x){
    for (int i = 0; i < n; i++ ){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {0, 1, 4, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    cout << search(arr, n, x);
    return 0;
}