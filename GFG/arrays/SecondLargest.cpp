#include <iostream>
using namespace std;

/*
The largest and secondLargest variables are initialized to the smallest possible integer (INT_MIN).
The loop iterates through the array, updating the largest and secondLargest variables as needed.
If there is no second-largest element, it prints an error message.
The main function initializes an array and calls the SecongLargest function to find and print the second-largest element.
*/

int SecongLargest(int arr[], int n)
{
    if (n < 2)
    {
        cout << "Array should have at least two elements.";
        return -1; // Error code indicating the array is too small
    }

    int largest = INT_MIN; // Initialize with smallest possible integer
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] < largest)
        {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN)
    {
        cout << "There is no second-largest element in the array.";
        return -1; // Error code indicating no second-largest element
    }

    return secondLargest;
}

int main()
{
    int arr[] = {5, 10, 3, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = SecongLargest(arr, n);

    if (result != -1)
    {
        cout << "The second-largest element is: " << result << endl;
    }

    return 0;
}
