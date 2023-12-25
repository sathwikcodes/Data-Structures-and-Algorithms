#include <iostream>
using namespace std;

int SearchNaive(int arr[], int k, int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int SearchEfficient(int arr[], int k, int low, int high, int n)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return mid;

        // Check if the left half is sorted
        /* Check for Sorted Half:
        Determine if the left or right half of the rotated array is sorted by comparing arr[low] with arr[mid]. Adjust the search range accordingly.*/

        if (arr[low] <= arr[mid])
        {
            // Check if k lies in the left half
            if (k >= arr[low] && k < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        /*  Update Search Range:
            Depending on whether the target element k lies in the left or right sorted half, update the low or high accordingly.*/
        else
        {
            // Check if k lies in the right half
            if (k > arr[mid] && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    // If the element is not found
    return -1;
}

int main()
{
    int arr[] = {10, 20, 40, 60, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    cout << "Naive: " << SearchNaive(arr, k, n) << endl;
    cout << "Efficient: " << SearchEfficient(arr, k, 0, n - 1, n) << endl;
    return 0;
}