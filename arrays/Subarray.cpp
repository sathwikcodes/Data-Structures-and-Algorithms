#include<iostream>
using namespace std;

//  to determine if there exists a subarray (contiguous subsequence) with a given sum in an array.

/*
The SubarraySum function uses a brute-force approach with two nested loops.
The outer loop (i) iterates through each element of the array.
The inner loop (j) calculates the sum of subarrays starting from the current outer loop index.
If any subarray sum equals the given sum, the function returns true; otherwise, it returns false.
*/
int SubarraySum(int arr[], int n, int sum){
    for (int i = 0; i < n; i++){
        int curr = 0;
        for (int j = i; j < n; j++){
            curr += arr[j];
        }
        if(curr==sum){
            return true;
        }
    }
    return false;
}

/*
The subArraySumEfficient function uses a more efficient sliding window approach.
It initializes two pointers (s and i) and a curr variable to track the sum of the current subarray.
The outer loop (i) iterates through each element of the array.
The function maintains a sliding window by adjusting the s pointer and updating curr.
If the current subarray sum equals the given sum, the function returns true; otherwise, it continues the iteration.

*/

int subArraySumEfficient(int arr[], int n, int sum){
    int s = 0;
    int curr = 0;
    for (int i = 0; i < n;i++){
        curr += arr[i];
        while(sum < curr){
            curr -= arr[s];
            s++;
        }
        if(curr == sum){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {5, 8, 6, 13, 3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 19;
    cout << subArraySumEfficient(arr, n, sum);
    return 0;
}