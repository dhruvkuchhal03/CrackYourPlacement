#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <stack>
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> temp;

        for (int i = 0; i < s.length(); i++)
        {
            if (temp.empty())
            {
                temp.push(s[i]);
            }
            else if (temp.top() == '(' && s[i] == ')' ||
                     temp.top() == '[' && s[i] == ']' ||
                     temp.top() == '{' && s[i] == '}')
            {
                temp.pop();
            }
            else
            {
                temp.push(s[i]);
            }
        }
        if (temp.empty())
        {
            return true;
        }
        return false;
    }
};