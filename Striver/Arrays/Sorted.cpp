#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false; // If any element is greater than its next element, array is not sorted
    }
    return true; // If no such pair is found, array is sorted
}

int main(){
    int arr[] = {1, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is : " << isSorted(arr, n);
    return 0;
}