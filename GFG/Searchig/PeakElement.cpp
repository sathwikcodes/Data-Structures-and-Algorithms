#include<iostream>
using namespace std;

// Peak element -  an element in an array whhere the left and right elements are smaller than it.
// 1. Naive solution - O(n)

int PeakNaive(int arr[], int n){
    if(n ==1 ){
        return arr[0];
    }
    if(arr[0] >= arr[1]){
        return arr[0];
    }
    if(arr[n-1] >= arr[n-2]){
        return arr[n - 1];
    }
    for(int i = 1; i < n-1; i++){
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}

/* here we use binary search approach.
1. first we compute mid value
2. if mid is peak element we return mid.
3. else we will go to left side for searching if left element of mid is higher than it and vice versa.
*/

// 2. Efficient solution - O(logn)


int PeakEfficient(int arr[], int n){
    int low = 0;
    int high = n - 1;
    while(low<=high){
        int mid = (low + high) / 2;
        if((mid == 0 || arr[mid - 1 ] <= arr[mid]) && (mid==n-1  || arr[mid+1] <= arr[mid] ))
            return mid;
        if(mid > 0 && arr[mid] - 1 >= arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<PeakNaive(arr, n)<<endl;
    cout<<PeakEfficient(arr, n)<<endl;
    return 0;
}