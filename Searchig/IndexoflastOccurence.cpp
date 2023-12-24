#include <iostream>
using namespace std;

int LastOccurence(int arr[], int low, int high, int x, int n)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] > x)
    {
        return LastOccurence(arr, low, mid - 1, x, n);
    }
    else if (arr[mid] < x)
    {
        return LastOccurence(arr, mid + 1, high, x, n);
    }
    else
    {
        if (mid == n - 1 || arr[mid] != arr[mid + 1])
        {
            return mid;
        }
        else
        {
            return LastOccurence(arr, mid + 1, high, x, n);
        }
    }
}

int main()
{
    int arr[] = {2, 4, 4, 4, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int result = LastOccurence(arr, 0, n - 1, x, n);

    if (result != -1)
    {
        cout << "Last occurrence of " << x << " is at index " << result << endl;
    }
    else
    {
        cout << x << " not found in the array." << endl;
    }

    return 0;
}
