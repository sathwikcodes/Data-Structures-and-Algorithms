#include <iostream>
using namespace std;

//we are assuming the first element as largest and if next element in larger then update the largest var value.

int LargestNum(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    int arr[] = {0, 2, 3, 5, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << LargestNum(arr, n);
    return 0;
}