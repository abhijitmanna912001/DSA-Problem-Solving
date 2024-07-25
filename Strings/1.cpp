#include <iostream>
using namespace std;

int main()
{
    string str1 = "Abhijit";
    string str2 = "Manna";

    if (str1.find(str2) == string::npos)
        cout << "Not Found" << endl;
    else
        cout << "Found" << endl;
    return 0;
}