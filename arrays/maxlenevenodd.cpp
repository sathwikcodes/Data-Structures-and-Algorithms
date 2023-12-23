#include <iostream>
using namespace std;

// finding the maximum length of subarrays with alternating even and odd numbers.

/*The outer loop (for (int i = 0; i < n; i++)) iterates over each element of the array.
The inner loop (for (int j = i + 1; j < n; j++)) checks for alternating even and odd elements in the subarray.
The variable curr keeps track of the current length of the alternating subarray.
The result res is updated with the maximum length encountered.*/
int MaxlenEvenOdd(int arr[], int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
                curr++;
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}

/*
It uses a single loop to iterate over the array.
The variable curr is used to keep track of the current length of the alternating subarray.
It checks if the current and previous elements have alternating parity (even-odd or odd-even).
If the condition is met, it increments curr and updates the result res.
If the condition is not met, it resets curr to 1.
*/

int MaxlenEvenOddEfficient(int arr[], int n)
{
    int res = 1;
    int curr = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] == 0))
        {
            curr++;
            res = max(res, curr);
        }
        else
            curr = 1;
    }
    return res;
}

int main()
{
    int arr[] = {5, 10, 20, 6, 3, 8},
        int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaxlenEvenOddEfficient(arr, n);
    return 0;
}