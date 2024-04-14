#include <bits/stdc++.h>
using namespace std;

// vector<int> Union(int arr1[], int arr2[], int n1, int n2){
//     vector<int> temp;
//     for (int i = 0; i < n1; i++){
//         for (int j = 0; j < n2; j++){
//             if(arr1[i] == arr2[j]){
//                 temp.push_back(arr1[i]);
//             }
//         }
//     }
//     return temp;
// }

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    vector<int> Union;
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);
    for (auto &it : s)
        Union.push_back(it);
    return Union;
}

// Two Pointer Approach

vector<int> FindUnionPointer(int arr1[], int arr2[], int n, int m)
{
    vector<int> Union;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
            {
                Union.push_back(arr1[i]);
                i++;
            }
        }
        else
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
            {
                Union.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n) // IF any element left in arr1
        {
            if (Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        while (j < m) // If any elements left in arr2
        {
            if (Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
        return Union;
    }
}

int main()

{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}