#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef long long int ll;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;

        for (ll i = 0; i < nums.size(); i++)
        {
            for (ll j = i + 1; j < nums.size(); j++)
            {
                ll l = j + 1;
                ll h = nums.size() - 1;

                while (l < h)
                {
                    ll sum = nums[i];
                    sum += nums[j];
                    sum += nums[l];
                    sum += nums[h];
                    if (sum == target)
                    {
                        s.insert({nums[i], nums[j], nums[l], nums[h]});
                        l++;
                        h--;
                    }
                    else if (sum < target)
                    {
                        l++;
                    }
                    else
                    {
                        h--;
                    }
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