#include <iostream>
#include <algorithm>
using namespace std;

void reverseString(char ch[], int n)
{
    int i = 0, j = n - 1;

    while (i <= j)
    {
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}

int main()
{
    char input[100];
    cout << "Enter a string: ";
    cin >> input;

    int n = 0;
    while (input[n] != '\0')
    {
        n++;
    }

    reverseString(input, n);

    cout << "Reversed string: " << input << endl;
    return 0;
}