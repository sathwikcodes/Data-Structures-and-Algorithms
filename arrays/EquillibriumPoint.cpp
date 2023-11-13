#include<iostream>
using namespace std;

bool Epoint(int arr[], int n){
    for (int i = 0; i < n; i++){
        int lsum = 0;
        int rsum = 0;
        for (int j = 0; j < i; j++){
            lsum = lsum + arr[j];
        }
        for (int k = i + 1; k < n; k++){
            rsum = rsum + arr[k];
        }
        if(lsum == rsum){
            return true;
        }
    }
    return false;
}

bool EpointEfficient(int arr[], int n){
    int res = 0;
    for (int i = 0; i < n; i++){
        res = res + arr[i];
    }
    int leftsum = 0;
    for (int i = 0; i < n; i++){
        res -= arr[i];
        if(leftsum == res)
            return true;
        leftsum += arr[i];
    }
    return false;
}


int main(){
    int arr[] = {3, 4, 8, -9, 20, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << EpointEfficient (arr, n);
    return 0;
}