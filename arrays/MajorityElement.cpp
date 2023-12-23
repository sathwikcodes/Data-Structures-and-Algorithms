#include<iostream>
using namespace std;

// Majority Element : An element that appears more than n/2 times, where n is the size of the array.

// brute-force solution. It iterates through each element in the array and, for each element, counts the occurrences of that element in the rest of the array. If the count is greater than n/2, it returns the majority element.

int MajorityElement(int arr[],int n){
    for (int i = 0; i < n; i++){
        int count = 1;
        for (int j = i + 1; j < n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n/2){
            return i;
        }
    }
    return -1;
}

// Boyer-Moore Voting Algorithm. It iterates through the array once to find a potential candidate for the majority element. In the second pass, it verifies if the candidate is the majority element by counting its occurrences. If it is, it returns the majority element
int MajorityElementEfficient(int arr[], int n)
{
    int res = 0;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }


    // Verify if the found element is the majority element
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
    }

    if (count > n / 2)
    {
        return arr[res];
    }
    else
    {
        return -1; // No majority element found
    }
}

int main(){
    int arr[] = {1, 4, 3, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MajorityElementEfficient(arr, n);
    return 0;
}