#include <iostream>
using namespace std;

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
