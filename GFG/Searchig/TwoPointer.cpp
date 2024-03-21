#include <iostream>
using namespace std;

bool TwopointerNaive(int arr[], int n, int sum)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                return true;
            }
        }
    }
    return false;
}


// Here we take low as first element and high as last element and if the sum of them is equal to required one we return it. else if the sum is greater then high value is reduced from n-1 to arr[n-2]. similarly if sum is less then low value is incremented.
bool TwopointerEfficient(int arr[], int n, int sum)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int currentSum = arr[low] + arr[high];
        if (currentSum == sum)
        {
            return true;
        }
        else if (currentSum > sum)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return false;
}

int main()
{
    int arr[] = {3, 5, 9, 2, 8, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 17;
    cout << TwopointerNaive(arr, n, sum) << endl;
    cout << TwopointerEfficient(arr, n, sum) << endl;
    return 0;
}