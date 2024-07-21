#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> outdeg(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[it].push_back(i);
                outdeg[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (outdeg[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node])
            {
                outdeg[it]--;
                if (outdeg[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};