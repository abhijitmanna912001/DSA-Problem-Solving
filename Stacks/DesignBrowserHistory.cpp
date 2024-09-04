#include <iostream>
#include <stack>
using namespace std;

class BrowserHistory
{
    stack<string> browserStack, fwdStack;

public:
    BrowserHistory(string homepage)
    {
        browserStack.push(homepage);
    }

    void visit(string url)
    {
        while (!fwdStack.empty())
            fwdStack.pop();

        browserStack.push(url);
    }

    string back(int steps)
    {
        while (steps--)
        {
            if (browserStack.size() > 1)
            {
                fwdStack.push(browserStack.top());
                browserStack.pop();
            }
            else
                break;
        }
        return browserStack.top();
    }

    string forward(int steps)
    {
        while (steps--)
        {
            if (!fwdStack.empty())
            {
                browserStack.push(fwdStack.top());
                fwdStack.pop();
            }
            else
                break;
        }
        return browserStack.top();
    }
};

int main()
{

    return 0;
}