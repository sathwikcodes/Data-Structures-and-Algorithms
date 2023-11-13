#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {3, 5, 7, 8, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, n);
    return 0;
}

// Reverse a vector
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> arr;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         arr.push_back(x);
//     }
//     reverse(arr.begin(), arr.end());
//     for (auto x : arr)
//     {
//         cout << x << " ";
//     }
// }