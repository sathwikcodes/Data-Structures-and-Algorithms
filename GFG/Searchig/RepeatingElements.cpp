#include <iostream>
#include <algorithm>
using namespace std;

int SuperNaiveRepeating(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int NaiveRepeating(int arr[], int n)
{
    // Sort the array first.
    sort(arr, arr + n);
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
    return -1;
}

// Another efficient solution will be creating a temp array with size of original array and if the element should be marked as true once traversed in the visited array. if the element is occured again and true in visited array then it is the repeating element.

// new efficient for array with elements without 0.

/*
Phase 1: Detecting the Intersection Point (Cycle Detection)

Initialize two pointers, slow and fast, both pointing to the first element of the array.
Move slow one step at a time and fast two steps at a time.
If there is a cycle in the array, the two pointers will eventually meet at some point within the cycle. This is guaranteed by Floyd's Tortoise and Hare algorithm.
Phase 2: Finding the Starting Point of the Cycle

Reset the slow pointer to the first element of the array.
Move both slow and fast one step at a time until they meet again. The meeting point is the starting point of the cycle.
The starting point of the cycle is the repeated element in the array.
*/
int RepeatingEfficient(int arr[], int n)
{
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

// for elements starting with 0.

int RepeatingEfficient0(int arr[], int n)
{
    int slow = arr[0] + 1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast]] + 1;

    } while (slow != fast);
    slow = arr[0] + 1;
    while (slow != fast)
    {
        fast = arr[fast] + 1;
        slow = arr[slow] + 1;
    }
    return slow - 1;
}

int main()
{
    int arr[] = {1, 3, 2, 4, 6, 5, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The repeating element is: " << NaiveRepeating(arr, n) << endl;
    cout << "The super naive algorithm : " << SuperNaiveRepeating(arr, n) << endl;
    cout << "Using cycle Algorithm : " << RepeatingEfficient(arr, n) << endl;
    cout << "Using cycle Algorithm with 0 element: " << RepeatingEfficient0(arr, n) << endl;
    return 0;
}