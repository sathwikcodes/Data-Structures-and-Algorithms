#include <bits/stdc++.h>
using namespace std;

// Brute-force approach - sort array in ascending order and return second index and second last index element.
// better Approach - get large and small elements from first iteration and do another traversal and find second small and second large.
// optimal approach - 


int Second_Smallest(int arr[], int n){
    int min = INT_MAX;
    int secondmin = INT_MAX;
    for (int i = 0; i < n;i++){
        if(arr[i] < min){
            secondmin = min;
            min = arr[i];
        }else if(arr[i] < secondmin && arr[i] != min){
            secondmin = arr[i];
        }
    }
    return  secondmin;
}

int Second_Largest(int arr[], int n){
    int max = INT_MIN;
    int secondmax = INT_MIN;
    for (int i = 0; i < n;i++){
        if(arr[i] > max){
            secondmax = max;
            max = arr[i];
        }else if(arr[i] > secondmax && arr[i] != max){
            secondmax = arr[i];
        }
    }
    return secondmax;
}

int main(){
    int arr[] = {1, 24, 5, 5, 66, 7, 8, 43, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Second Smallest Element  is :"<<Second_Smallest(arr,n);
    cout << "\n\nSecond Largest Element is :"<<Second_Largest(arr,n); 
    return 0;
}