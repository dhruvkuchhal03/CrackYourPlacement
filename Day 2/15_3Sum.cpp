#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1;
            int h = nums.size() - 1;

            while (l < h)
            {
                int sum = nums[i] + nums[l] + nums[h];
                if (sum == 0)
                {
                    s.insert({nums[i], nums[l], nums[h]});
                    l++;
                    h--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    h--;
                }
            }
        }
        for (auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};