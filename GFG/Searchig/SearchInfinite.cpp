#include<iostream>
using namespace std;

int BinarySearchR(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return BinarySearchR(arr, low, mid - 1, x);
    else
        return BinarySearchR(arr, mid + 1, high, x);
}

int SearchNaive(int arr[],int x){
    int i = 0;
    while(true){
        if (arr[i] == x)
            return i;
        if (arr[i] > x)
            return -1;
        i++;
    }
}

/*
Check if the first element is equal to x:

If arr[0] is equal to x, return the index 1 (assuming the index is 1-based).
Exponential Search for Range:

Initialize i to 1 (starting index).
While arr[i] is less than x, double the value of i (exponential growth).
This step identifies a range where x might be present, i.e., between i/2 and i.
Binary Search within Identified Range:

Call the BinarySearchR function within the range [i/2 + 1, i - 1] to perform a binary search.
*/

int SearchEfficient(int arr[], int x){
    if(arr[0] == x)
        return 1;
    int i = 1;
    while(arr[i] < x){
        i = i * 2;
    }
    if(arr[i] == x)
        return i;
    return BinarySearchR(arr, i/2 + 1, i - 1, x);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 5;

    // SearchNaive
    int indexNaive = SearchNaive(arr, x);
    cout << "Naive Search Result: " << indexNaive << endl;

    // SearchEfficient
    int indexEfficient = SearchEfficient(arr, x);
    cout << "Efficient Search Result: " << indexEfficient << endl;

    return 0;
}
