#include <iostream>
using namespace std;

int countOnesNaive(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
    }
    return count;
}

// efficient approach -- use binary search, as the array is sorted find mid if it is 0 go to right and count 1''s and if it is 1 then go left and perform binary again.

int countOnes(int arr[], int low, int high, int n)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 0)
        {
            return countOnes(arr, mid + 1, high, n);
        }
        else if (arr[mid] == 1 && (mid == n - 1 || arr[mid + 1] == 0))
        {
            return (n - mid);
        }
        else
        {
            return countOnes(arr, low, mid - 1, n);
        }
    }

    return 0;
}

int main()
{
    int arr[] = {1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Naive approach
    cout << "Naive Count: " << countOnesNaive(arr, n) << endl;

    // Efficient approach
    cout << "Efficient Count: " << countOnes(arr, 0, n - 1, n) << endl;

    return 0;
}