#include <iostream>
using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray[i] = array[leftIndex + i];
    }
    for (int j = 0; j < rightArraySize; j++)
    {
        rightArray[j] = array[midIndex + 1 + j];
    }
    int index = leftIndex;
    int i = 0;
    int j = 0;
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else
        {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }
    while (i < leftArraySize)
    {
        array[index] = leftArray[i];
        index++;
        i++;
    }
    while(j < rightArraySize)
    {
        array[index] = rightArray[j];
        index++;
        j++;
    }
};

void mergeSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex)
        return;
    
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

int main(){
    int arr[] = {1, 3,  7, 8, 2, 4, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;

    mergeSort(arr, leftIndex, rightIndex);

    for(auto value : arr){
        cout << value << " ";
    }
}