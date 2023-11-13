#include <iostream>
using namespace std;

void MoveZeroes(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 0, 0, 4, 0, 40, 20, 4, 5, 0, 2, 5, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    MoveZeroes(arr, n);
    return 0;
}
