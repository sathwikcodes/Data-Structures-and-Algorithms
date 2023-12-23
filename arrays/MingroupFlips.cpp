#include<iostream>
using namespace std;

//prints the indices where there is a change in a binary array.
/*If a change is detected (i.e., arr[i] != arr[i-1]), it checks whether the current element is different from the first element.
If true, it prints "From i to ".
If false, it prints i - 1 (indicating the end of the flip range) followed by a newline.*/
void printFlip(bool arr[], int n)
{
    for (int i = 1; i < n;i++){
        if(arr[i] != arr[i-1]){
            if(arr[i] != arr[0])
                cout << "From " << i << " to ";
            else
                cout << i - 1 << endl;
        }
    }
    if(arr[n-1] != arr[0])
        cout << (n - 1) << endl;
}

int main(){
    bool arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printFlip(arr, n);
    return 0;
}