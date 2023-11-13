#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Trappingwater(int arr[], int n ){
    int result = 0;
    for (int i = 1; i < n - 1; i++){
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
            lmax = max(lmax, arr[j]);
        int rmax = arr[i];
        for (int j = i + 1; j < n; j++){
            rmax = max(rmax, arr[j]);

        }
        result += (min(lmax, rmax) - arr[i]);
    }
    return result;
}

int TrappingwaterEfficient(int arr[], int n){
    int result = 0;
    int lmax[n];
    int rmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++){
        lmax[i] = max(arr[i], lmax[i - 1]);
    }
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--){
        rmax[i] = max(arr[i], rmax[i + 1]);
    }
    for (int i = 1; i < n - 1;i++){
        result += (min(lmax[i], rmax[i]) - arr[i]);
    }
    return result;
}

int main(){
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << TrappingwaterEfficient(arr, n);
    return 0;
}