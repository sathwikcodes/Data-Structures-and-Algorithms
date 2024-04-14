#include<bits/stdc++.h>
using namespace std;


int Missing(int arr[], int N,int n){
    int s2 = 0;
    int s1 = (N * (N + 1)) / 2;
    for (int i = 0; i < n; i++){
        s2 = s2 + arr[i];
    }

    int missingNum = s1 - s2;
    return missingNum;
}

int main(){
    int arr[] = {1, 2, 4, 5};
    int N = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << Missing(arr, N,n);
    return 0;
}