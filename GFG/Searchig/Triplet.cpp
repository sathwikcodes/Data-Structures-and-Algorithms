#include <iostream>
using namespace std;

bool TripletNaive(int arr[], int n, int sum)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool TripletEfficient(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 1; i++)
    {
        int first = i + 1;
        int last = n - 1;
        while (first < last)
        {
            int currentSum = arr[i] + arr[first] + arr[last];
            if (currentSum == sum)
            {
                return true;
            }
            else if (currentSum < sum)
            {
                first++;
            }
            else
            {
                last--;
            }
        }
    }
    return false;
}

bool isTriplet(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 2; i++)
    {
        if (TripletEfficient(arr, n, sum - arr[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {3, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 14;
    cout << "Triplet exists in the array: ";
    if (TripletNaive(arr, n, sum) || isTriplet(arr, n, sum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
