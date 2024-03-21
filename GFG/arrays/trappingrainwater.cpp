#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// amount of water that can be trapped between the bars (represented by elements in the array)

/*
The Trappingwater function uses a brute-force approach with nested loops.
For each element at index i, it calculates the maximum height to the left (lmax) and the maximum height to the right (rmax).
The amount of water that can be trapped at that position is determined by min(lmax, rmax) - arr[i].
The total trapped water is accumulated in the result variable.
*/
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

/*
The TrappingwaterEfficient function uses an efficient dynamic programming approach.
It precomputes the left maximum height (lmax) and the right maximum height (rmax) for each element in separate arrays.
The trapped water at each position is calculated using the precomputed lmax and rmax arrays.
The total trapped water is accumulated in the result variable.
*/

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