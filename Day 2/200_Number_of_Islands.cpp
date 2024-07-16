#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == '0')
            return;

        grid[row][col] = '0';

        dfs(grid, row - 1, col); // up
        dfs(grid, row + 1, col); // down
        dfs(grid, row, col - 1); // left
        dfs(grid, row, col + 1); // right
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;

        int m = grid[0].size();
        int count = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == '1')
                {
                    count++;
                    dfs(grid, row, col);
                }
            }
        }

        return count;
    }
};