/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
class Solution
{
private:
    int oldColor;
    int newColor;
    int dimY;
    int dimX;
    void fill(vector<vector<int>> &image, int y, int x)
    {
        if (y < 0 || y >= dimY || x < 0 || x >= dimX || image[y][x] != oldColor)
            return; // boundary conditions
        image[y][x] = newColor;
        for (int i = 0; i < 4; i++)
        {
            fill(image, y + dy[i], x + dx[i]);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor_)
    {
        dimY = image.size();
        dimX = image[0].size();
        oldColor = image[sr][sc];
        newColor = newColor_;
        if (oldColor != newColor)
            fill(image, sr, sc);
        return image;
    }
};
// @lc code=end