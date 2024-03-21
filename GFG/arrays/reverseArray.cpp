#include <iostream>
using namespace std;

/*
The function reverseArray takes an integer array arr and its size n as parameters.
It uses two pointers, low and high, initialized at the beginning and end of the array, respectively.
It swaps elements at low and high positions, increments low, and decrements high until low is no longer less than high.
After reversing the array in place, the function prints the reversed array.
*/

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

/*
It reads the size of the vector n and elements from the user.
It then uses the reverse function from the <algorithm> header to reverse the vector in-place.
*/
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