#include<iostream>
using namespace std;


//use first occurrence and last occurence function here.

int firstOccurence(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int countOccurence(int arr[], int n, int x){
    int first = firstOccurence(arr, n, x);
    if(first == -1)
        return 0;
    else
        return (lastOccurence(arr, n, x) - first + 1);
}

int main(){

    int arr[] = {10, 20, 20, 20, 40, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 20;
    cout<<countOccurence(arr, n, x);
    return 0;
}