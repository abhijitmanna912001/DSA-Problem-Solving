#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char ch[], int n)
{
    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (ch[i] == ch[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    char str[1000];

    cout << "Enter a string: ";
    cin.getline(str, sizeof(str));

    int length = strlen(str);

    if (checkPalindrome(str, length))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;
    return 0;
}