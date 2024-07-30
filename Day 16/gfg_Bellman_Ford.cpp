#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Function to implement Bellman Ford
     * edges: vector of vectors which represents the graph
     * S: source vertex to start traversing graph with
     * V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        for (int i = 0; i < V - 1; ++i)
        {
            for (const auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }

        return dist;
    }
};

int main()
{
    int V = 6;
    vector<vector<int>> edges = {
        {3, 2, 6},
        {5, 3, 1},
        {0, 1, 5},
        {1, 5, -3},
        {1, 2, -2},
        {3, 4, -2},
        {2, 4, 3}};

    int S = 0;
    Solution obj;
    vector<int> dist = obj.bellman_ford(V, edges, S);

    for (int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
