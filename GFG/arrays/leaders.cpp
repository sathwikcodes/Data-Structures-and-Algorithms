#include<iostream>
using namespace std;

// A leader in an array is an element that is greater than all the elements to its right.
// It initializes curr_ldr with the last element of the array and prints it. Then, it iterates from the second-to-last element towards the first element. For each element, if it is greater than the current leader (curr_ldr), it updates the current leader

void leader(int arr[], int n){
    int curr_ldr = arr[n - 1];
    cout << curr_ldr << " ";
    for (int i = n - 2; i >= 0; i--){
        if(curr_ldr < arr[i]){
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }
}

int main(){
    int arr[] = {1, 3, 5, 6, 7, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    leader(arr, n);
    return 0;
}