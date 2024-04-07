// printing element with highest frequency
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // precompute
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    //iterating in mpp to know the frequency of every element.
    int maxFrequency = 0;
    int elementwithmax = -1;

    for(auto it : mpp){
        if(it.second > maxFrequency){
            maxFrequency = it.second;
            elementwithmax = it.first;
        }

    }
    cout << elementwithmax << "->" << maxFrequency << endl;
    return 0;
}