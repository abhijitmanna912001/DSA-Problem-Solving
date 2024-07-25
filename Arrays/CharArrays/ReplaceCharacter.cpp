#include <iostream>
using namespace std;

void replaceCharacter(char ch[], int n)
{
    int index = 0;
    while (ch[index] != '\0')
    {
        char currChar = ch[index];
        if (currChar == '@')
            ch[index] = ' ';
        index++;
    }
}

int main()
{
    char inputString[100];
    cout << "Enter a string: ";
    cin.getline(inputString, 100);

    replaceCharacter(inputString, 100);

    cout << "Modified string: " << inputString << endl;
    return 0;
}