#include <iostream>
#include <vector>
using namespace std;

void maxProfitFinder(vector<int> &prices, int i, int &minPrice, int &maxProfit)
{
    if (i == prices.size())
        return;

    if (prices[i] < minPrice)
        minPrice = prices[i];
    int tdaysProfit = prices[i] - minPrice;
    if (tdaysProfit > maxProfit)
        maxProfit = tdaysProfit;

    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main()
{

    return 0;
}