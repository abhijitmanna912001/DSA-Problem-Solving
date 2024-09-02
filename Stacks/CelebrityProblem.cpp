#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        stack<int> st;
        for (int i = 0; i < n; ++i)
            st.push(i);

        while (st.size() != 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (mat[a][b])
                st.push(b);
            else
                st.push(a);
        }

        int mightBeCelebrity = st.top();
        st.pop();

        for (int i = 0; i < n; i++)
        {
            if (mat[mightBeCelebrity][i] != 0)
                return -1;
        }

        for (int i = 0; i < n; ++i)
        {
            if (mat[i][mightBeCelebrity] == 0 && i != mightBeCelebrity)
                return -1;
        }
        return mightBeCelebrity;
    }
};

int main()
{

    return 0;
}