#include <iostream>
using namespace std;

// find the maximum sum of a subarray of size k in an array.

/*
The maxSum function uses a nested loop to iterate through all possible subarrays of size k.
It calculates the sum of each subarray and keeps track of the maximum sum (res).
*/
int maxSum(int arr[], int n, int k)
{
    int res = INT_MIN;
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum = sum + arr[i + j];
            res = max(res, sum);
        }
    }
    return res;
}

/*
Initialization:

curr is initialized to the sum of the first k elements in the array. This serves as the initial window sum.
Sliding Window Iteration:

The function then iterates from k to n-1, representing the end of the array.
At each iteration, it adds the current element arr[i] and subtracts the element arr[i - k] that is no longer part of the current window.
This sliding window approach helps avoid redundant calculations and reduces the time complexity.
Updating Maximum Sum:

The variable res keeps track of the maximum sum encountered during the iteration.
At each step, the function compares the current sum (curr) with the maximum sum (res) and updates res if the current sum is greater.
Result:

The final result returned by the function is the maximum sum of any subarray of size k.
*/

int maxSumEfficient(int arr[], int n, int k){
    int curr = 0;
    for (int i = 0; i < k; i++){
        curr += arr[i];
    }
    int res = curr;
    for (int i = k; i < n; i++){
        curr += (arr[i] - arr[i-k]);
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << maxSumEfficient(arr, n, k);
    return 0;
}
