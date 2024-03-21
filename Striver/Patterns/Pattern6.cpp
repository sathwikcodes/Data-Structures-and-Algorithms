#include <iostream>
using namespace std;

void Pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

int main()
{
    Pattern(6);
    return 0;
}