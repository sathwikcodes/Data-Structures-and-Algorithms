#include<iostream>
using namespace std;

void insert(int arr[], int n, int x, int idx){
    if(idx < 0 || idx > n){
        cout << "Invalid";
    }
    else{
        for (int i = n; i > idx; i--)
        {
            arr[i] = arr[i - 1];
           
        }
        arr[idx] = x;
        n++;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main(){
    int arr[] = {0, 1, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1223;
    int idx = 4;
    insert(arr, n, x, idx);
    return 0;
}