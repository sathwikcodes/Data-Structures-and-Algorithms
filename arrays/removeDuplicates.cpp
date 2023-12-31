#include <iostream>
using namespace std;

// If the current element arr[i] is different from the previous unique element (arr[res - 1]), it is considered a new unique element, and it is placed at the position res. The res pointer is then incremented.

int removeDuplicates(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeDuplicates(arr, n);
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}