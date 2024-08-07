#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int L, int R)
{
    bool sieve[R + 1];
    for (int i = 0; i <= R; ++i)
    {
        if (i == 0 || i == 1)
            sieve[i] = false;
        else
            sieve[i] = true;
    }

    for (int i = 2; i * i <= R; ++i)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= R; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = L; i <= R; ++i)
    {
        if (sieve[i])
            cnt++;
    }

    return cnt;
}

int main()
{

    return 0;
}