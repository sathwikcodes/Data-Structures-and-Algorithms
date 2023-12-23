#include <iostream>
using namespace std;

/*
The function takes an array of stock prices price and its size n as parameters.
It initializes the profit variable to zero.
It iterates through the array starting from the second day (i = 1).
If the current day's price is higher than the previous day's price, it adds the difference to the profit.
The final profit represents the maximum profit that can be obtained by buying and selling the stock multiple times.
*/

int maxProfit(int price[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
            profit += price[i] - price[i - 1];
    }
    return profit;
}

int main()
{
    int price[] = {1, 5, 3, 8, 12};
    int n = sizeof(price) / sizeof(price[0]);
    cout << maxProfit(price, n);
    return 0;
}
