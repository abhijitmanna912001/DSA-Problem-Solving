#include <iostream>
using namespace std;

int getPaintWays(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * (k - 1);
    int ans = (k - 1) * (getPaintWays(n - 1, k) + getPaintWays(n - 2, k));
    return ans;
}

int main()
{
    int n = 2;
    int k = 4;
    int ans = getPaintWays(n, k);
    cout << ans << endl;
    return 0;
}