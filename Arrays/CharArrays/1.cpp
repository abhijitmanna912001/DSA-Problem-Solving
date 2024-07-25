#include <iostream>
#include <cstring>
using namespace std;

int findLength(char ch[], int size)
{
    int index = 0;
    while (ch[index] != '\0')
        index++;
    return index;
}

int main()
{
    char ch[100];
    cin >> ch;

    int len = findLength(ch, 100);
    cout << "Length of string is: " << len << endl;
    cout << "Length of string is: " << strlen(ch) << endl;
    return 0;
}