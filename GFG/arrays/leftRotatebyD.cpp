#include<iostream>
using namespace std;

// The reverse function takes an array arr and two indices low and high as input. It reverses the elements in the array between the indices low and high using a two-pointer approach.

// The leftRotate function takes an array arr, its size n, and an integer d representing the number of positions to rotate to the left. It performs a left rotation by calling the reverse function three times:

//Reverses the first d elements.
//Reverses the remaining elements.
//Reverses the entire array.
void reverse(int arr[], int low, int high)
{
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotate(int arr[], int n, int d){
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

int main(){
    int arr[] = {5,30,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    leftRotate(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}