#include<iostream>
using namespace std;

int FirstOccurencerecursive(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] > x)
        return FirstOccurencerecursive(arr, low, mid - 1, x);
    else if (arr[mid] < x)
        return FirstOccurencerecursive(arr, mid + 1, high, x);
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return FirstOccurencerecursive(arr, low, mid - 1, x);
    }
}

int LastOccurence(int arr[], int low, int high, int x, int n)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

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


int CountOccurence(int arr[], int n,int k){
    int first = FirstOccurencerecursive(arr, 0,n, k);
    int last = LastOccurence(arr, 0, n, k, n);
    return last - first + 1;
}

int main()
{
    int arr[] = {2, 4, 4, 4, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 9;

    int count = CountOccurence(arr, n, k);

    if (count != -1)
    {
        cout << "Count of occurrences of " << k << " is: " << count << endl;
    }
    else
    {
        cout << k << " not found in the array." << endl;
    }

    return 0;
}
