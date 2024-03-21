#include <iostream>
using namespace std;

void Pattern()
{
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    Pattern();
    return 0;
}