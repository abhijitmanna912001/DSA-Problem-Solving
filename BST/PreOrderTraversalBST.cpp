#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int canRepresentBST(int arr[], int N)
    {
        stack<int> s;
        int root = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] < root)
                return 0;

            while (!s.empty() && s.top() < arr[i])
            {
                root = s.top();
                s.pop();
            }

            s.push(arr[i]);
        }
        return 1;
    }
};

int main()
{

    return 0;
}