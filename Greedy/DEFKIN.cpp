#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;

        vector<int> xDim = {0, w + 1};
        vector<int> yDim = {0, h + 1};

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            xDim.push_back(x);
            yDim.push_back(y);
        }

        sort(xDim.begin(), xDim.end());
        sort(yDim.begin(), yDim.end());

        int maxWidth = 0;
        for (int i = 1; i < xDim.size(); i++)
            maxWidth = max(maxWidth, xDim[i] - xDim[i - 1] - 1);

        int maxHeight = 0;
        for (int i = 1; i < yDim.size(); i++)
            maxHeight = max(maxHeight, yDim[i] - yDim[i - 1] - 1);

        cout << maxWidth * maxHeight << endl;
    }

    return 0;
}
