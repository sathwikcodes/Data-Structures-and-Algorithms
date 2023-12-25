#include <iostream>
#include <climits> // Include this header for INT_MAX and INT_MIN
using namespace std;


//DOUBT??
// This function uses the binary search approach to efficiently find the partition points in both arrays.

    double
    getMedian(int arr1[], int arr2[], int n1, int n2) // n1,n2 - size of arr1 and arr2 
{
    // search range for 1st array
    int begin1 = 0, end1 = n1;
    while (begin1 <= end1)
    {
        int i1 = (begin1 + end1) / 2; // mid point
        int i2 = (n1 + n2) / 2 - i1;
        int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
        int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
        int min2 = (i2 == n2) ? INT_MAX : arr2[i2];
        int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];
        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
                return ((double(max(max1, max2) + min(min1, min2)) / 2));
            else
                return (double)max(max1, max2);
        }
        else if (max1 > min2)
            end1 = i1 - 1;
        else
            begin1 = i1 + 1;
    }
    return -1;
}

int main()
{
    // Example arrays
    int array1[] = {1, 3, 5, 7, 9};
    int array2[] = {2, 4, 6, 8, 10};

    // Sizes of the arrays
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    // Call the function
    double median = getMedian(array1, array2, size1, size2);

    // Print the result
    cout << "Median: " << median << endl;

    return 0;
}
