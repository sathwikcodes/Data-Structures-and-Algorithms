#include <iostream>
using namespace std;

// recursive approach

int BinarySearchR(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return BinarySearchR(arr, low, mid - 1, x);
    else
        return BinarySearchR(arr, mid + 1, high, x);
}

int main()
{
    int arr[] = {1, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    cout << BinarySearchR(arr, 0, n - 1, x);
    return 0;
}