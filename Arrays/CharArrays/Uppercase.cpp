#include <iostream>
using namespace std;

void convertToUpperCase(char ch[], int n)
{
    int index = 0;
    while (ch[index] != '\0')
    {
        char currChar = ch[index];
        if (currChar >= 'a' && currChar <= 'z')
        {
            ch[index] = currChar - 'a' + 'A';
        }
        index++;
    }
}

int main()
{
    char input[100];
    cout << "Enter a string: ";
    cin.getline(input, 100);

    convertToUpperCase(input, 100);

    cout << "Uppercase string: " << input << endl;
    return 0;
}