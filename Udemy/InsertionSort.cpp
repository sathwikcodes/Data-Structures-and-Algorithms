#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j > -1 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    int myArray[] = {6, 4, 2, 5, 1, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    insertionSort(myArray, size);

    for (auto value : myArray)
    {
        cout << value << " ";
    }
}