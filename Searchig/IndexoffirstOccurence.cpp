#include <iostream>
using namespace std;

int IndexofFirstNaive(int arr[], int n, int x)
{
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// efficient recursive solution

int FirstOccurencerecursive(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] > x)
        return FirstOccurencerecursive(arr, low, mid - 1, x);
    else if (arr[mid] < x)
        return FirstOccurencerecursive(arr, mid + 1, high, x);
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return FirstOccurencerecursive(arr, low, mid - 1, x);
    }
}

// efficient iterative solution

int FirstOccurenceIterative(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {15, 15, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;
    cout << IndexofFirstNaive(arr, n, x);
    return 0;
}