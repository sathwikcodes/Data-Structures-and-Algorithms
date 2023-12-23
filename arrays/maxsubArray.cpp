#include<iostream>
using namespace std;


int MaximumsubArray(int arr[], int n){
    int res = 0;
    for (int i = 0; i < n; i++){
        int curr = 0;
        for (int j = i; j < n; j++){
            curr += arr[j];
            res = max(res, curr);
        }
    }
    return res;
}

/*The function MaximumsubArrayEfficient is an optimized version using Kadane's algorithm.
It takes an array arr and its size n as parameters.
It initializes res and maxEnding with the first element of the array.
It uses a single loop to iterate over the array.
The variable maxEnding represents the maximum subarray sum ending at the current index.
It updates maxEnding by taking the maximum of the sum of the current element and the previous maxEnding or just the current element.
The result res is updated with the maximum subarray sum encountered.*/

int MaximumsubArrayEfficient(int arr[], int n){
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++){
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main(){
    int arr[] = {2, 1, -3, 4, 5, 6, -7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaximumsubArrayEfficient(arr, n);
    return 0;
}