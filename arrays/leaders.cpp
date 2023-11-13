#include<iostream>
using namespace std;

void leader(int arr[], int n){
    int curr_ldr = arr[n - 1];
    cout << curr_ldr << " ";
    for (int i = n - 2; i >= 0; i--){
        if(curr_ldr < arr[i]){
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }
}

int main(){
    int arr[] = {1, 3, 5, 6, 7, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    leader(arr, n);
    return 0;
}