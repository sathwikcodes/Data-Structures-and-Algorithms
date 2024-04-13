#include <bits/stdc++.h>
using namespace std;

int Duplicates(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            delete arr[i];
        }
    }
    return arr;
}

int DuplicatesLeetcode(int arr[], int n)
{
    if (n == 0)
        return 0;
    int j = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            arr[j++] = arr[i];
        }
    }
    return j;
}

int main()
{
    int arr[] = {1, 24, 5, 5, 66, 7, 8, 43, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array after removing Duplicates" << Duplicates(arr, n);
    return 0;
}