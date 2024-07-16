#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int inicolor = image[sr][sc];
        if (inicolor == color)
            return image;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            image[r][c] = color;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < image.size() && nc <= image[0].size() && image[nr][nc] == inicolor)
                {
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};