#include <iostream>
using namespace std;

void printMax(int n1, int n2, int n3)
{
    int ans1 = max(n1, n2);
    int finalAns = max(ans1, n3);
    cout << "Final ans is: " << finalAns << endl;
}

int main()
{
    printMax(75, 17, 9);
    return 0;
}