#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    string f(int &i, string s)
    {
        string ans = "";
        int num = 0;

        for (; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '[')
            {
                string temp = f(++i, s);
                for (; num > 0; num--)
                {
                    ans += temp;
                }
            }
            else if (s[i] == ']')
                return ans;
            else
                ans += s[i];
        }
        return ans;
    }

    string decodeString(string s)
    {
        int i = 0;
        return f(i, s);
    }
};