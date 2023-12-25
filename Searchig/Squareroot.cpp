#include<iostream>
using namespace std;

int SQNaive(int x){
    int i = 1;
    while(i*i <= x){
        i++;
    }
    return i-1;
}

int SQEfficient(int x)
{
    int low = 1;
    int high = x;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    int x = 49;
    cout << "Naive: " << SQNaive(x) << endl;
    cout << "Efficient: " << SQEfficient(x) << endl;
    return 0;
}