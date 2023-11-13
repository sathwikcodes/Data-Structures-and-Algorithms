#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int x){
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x){
            return mid;
        }else if( arr[mid] < x){
            low = mid + 1;
        }else if(arr[mid] > 1){
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    cout << BinarySearch(arr, n, x);
    return 0;
}