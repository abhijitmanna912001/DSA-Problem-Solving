#include <iostream>
using namespace std;

void lastOccurLTR(string &S, char P, int i, int &ans)
{
    if (i >= S.size())
        return;

    if (S[i] == P)
        ans = i;
    lastOccurLTR(S, P, i + 1, ans);
}

int main()
{
    string S;
    cin >> S;
    char P;
    cin >> P;
    int ans = -1;
    lastOccurLTR(S, P, 0, ans);
    cout << ans << endl;
    return 0;
}