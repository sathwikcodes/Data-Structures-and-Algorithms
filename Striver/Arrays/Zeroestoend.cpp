#include <iostream>
#include <vector>

using namespace std;

void move(vector<int> &arr)
{
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    int size = arr.size() - temp.size();
    for (int i = 0; i < size; i++)
    {
        temp.push_back(0);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

vector<int> moveZeroesOptimal(vector<int> a, int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return a;

    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main()
{
    vector<int> arr = {1, 5, 0, 0, 43, 0, 0, 7, 3};
    move(arr);
    return 0;
}
