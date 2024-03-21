#include <iostream>
using namespace std;

void Pattern(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j < n-i+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    Pattern(5);
    return 0;
}