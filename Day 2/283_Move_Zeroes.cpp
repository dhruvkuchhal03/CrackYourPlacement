#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        for (int p = i; p < nums.size(); p++)
        {
            nums[p] = 0;
        }
    }
};
