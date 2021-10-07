/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    static constexpr int dy[] = {-1, 0, 1, 0};
    static constexpr int dx[] = {0, 1, 0, -1};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int cnt_fresh = 0;
        int elapsed = 0;
        int dimY = grid.size();
        int dimX = grid[0].size();
        queue<pair<int, int>> q;
        vector<bool> vis(dimY * dimX, false);
        for (int i = 0; i < dimY; i++)
        {
            for (int j = 0; j < dimX; j++)
            {
                if (grid[i][j] == 1)
                    cnt_fresh++; // log all remaining fresh oranges
                else if (grid[i][j] == 2) {
                    q.emplace(i, j); // push all source points
                    vis[i * dimX + j] = true;
                }
            }
        }
        while (!q.empty())
        {
            if(cnt_fresh == 0) break; // no more fresh oranges, stop searching
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto [y, x] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int newY = y + dy[k];
                    int newX = x + dx[k];
                    if (newY >= 0 && newY < dimY && newX >= 0 && newX < dimX)
                    {
                        if (grid[newY][newX] == 1)
                        {
                            cnt_fresh--;
                            grid[newY][newX] = 2;
                            q.emplace(newY, newX);
                        }
                    }
                }
            }
            elapsed++;
        }
        return cnt_fresh == 0 ? elapsed : -1; // check if there're discrete groups that can't be reached
    }
};
// @lc code=end
