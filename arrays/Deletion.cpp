#include<iostream>
using namespace std;

void deletion(int arr[], int n , int idx){
    if (idx < 0 || idx > n){
        cout << "Invalid";
    }
    else{
        for (int i = idx; i < n; i++){
            arr[i] = arr[i + 1];
        }
        n--;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main(){
    int arr[] = {0, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int idx = 0;
    deletion(arr, n, idx);
    return 0;
}