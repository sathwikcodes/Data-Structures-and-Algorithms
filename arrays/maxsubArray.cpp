#include<iostream>
using namespace std;


int MaximumsubArray(int arr[], int n){
    int res = 0;
    for (int i = 0; i < n; i++){
        int curr = 0;
        for (int j = i; j < n; j++){
            curr += arr[j];
            res = max(res, curr);
        }
    }
    return res;
}


int MaximumsubArrayEfficient(int arr[], int n){
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++){
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main(){
    int arr[] = {2, 1, -3, 4, 5, 6, -7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaximumsubArrayEfficient(arr, n);
    return 0;
}