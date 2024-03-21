#include <iostream>
using namespace std;

int maxDiff(int arr[], int n)
{
    int res = arr[1] - arr[0];
    int minVal = arr[0];
    for (int j = 1; j < n; j++)
    {
        res = max(res, arr[j] - minVal);
        minVal = min(minVal, arr[j]);
    }
    return res;
}

int main()
{
    int arr[] = {7, 9, 5, 6, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxDiff(arr, n);
    return 0;
}