/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
class Solution
{
private:
    int dimY;
    int dimX;
    int maxArea;
    vector<bool> visited;
    int explore(vector<vector<int>>& grid, int y, int x)
    {
        if (y < 0 || y >= dimY || x < 0 || x >= dimX || grid[y][x] == 0)
        {
            return 0; // reach the grid boundary
        }
        if(visited[y * dimX + x] == false) {
            visited[y * dimX + x] = true;
            int area = 1;
            for(int i = 0; i < 4; i++) {
                area += explore(grid, y + dy[i], x + dx[i]);
            }    
            return area;
        }
        else return 0;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        dimY = grid.size();
        dimX = grid[0].size();
        maxArea = 0;
        visited.resize(dimY * dimX, false);
        for (int y = 0; y < dimY; ++y)
        {
            for (int x = 0; x < dimX; ++x)
            {
                if (grid[y][x] == 1 && visited[y * dimX + x] == false)
                    maxArea = max(explore(grid, y, x), maxArea);

            }
        }
        return maxArea;
    }
};
// @lc code=end
