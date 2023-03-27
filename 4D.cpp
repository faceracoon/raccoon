#include <iostream>
#include <stack>
#include <string>

using namespace std;

inline bool firstBrasket(char c)
{
    return ('(' == c ||
    '{' == c ||
    '[' == c);
}

inline bool isCompleted(char l, char r)
{
    return ('(' == l && ')' == r) ||
    ('[' == l && ']' == r) ||
    ('{' == l && '}' == r);
}

int main()
{
    string in = "()[]";
    stack<char> stack;
    for(string::const_iterator it(in.begin()), itEnd(in.end()); it != itEnd; ++it)
    {
        if(firstBrasket(*it))
        {
            stack.push(*it);
        }
        else if(isCompleted(stack.top(), *it))
        {
            stack.pop();
        }
        else
        {
            stack.push(*it);
            break;
        }
    }
    cout << (stack.empty() ? "yes" : "no") << endl;
    return 0;
}