#include<iostream>
using namespace std;

// moving the elements of the array to the left by one position, with the first element becoming the last.

//It performs a left rotation by storing the first element(arr[0]) in a temporary variable(temp).Then, it shifts the remaining elements to the left by one position.Finally, it places the temporary variable at the last position of the array.

void LeftRotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++){
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {5,30,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    LeftRotate(arr, n);
    return 0;
}