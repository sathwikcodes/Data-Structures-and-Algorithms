#include<iostream>
using namespace std;

int SubarraySum(int arr[], int n, int sum){
    for (int i = 0; i < n; i++){
        int curr = 0;
        for (int j = i; j < n; j++){
            curr += arr[j];
        }
        if(curr==sum){
            return true;
        }
    }
    return false;
}

int subArraySumEfficient(int arr[], int n, int sum){
    int s = 0;
    int curr = 0;
    for (int i = 0; i < n;i++){
        curr += arr[i];
        while(sum < curr){
            curr -= arr[s];
            s++;
        }
        if(curr == sum){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {5, 8, 6, 13, 3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 19;
    cout << subArraySumEfficient(arr, n, sum);
    return 0;
}