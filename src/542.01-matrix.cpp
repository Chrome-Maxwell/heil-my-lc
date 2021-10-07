/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    static constexpr int dy[] = {-1, 0, 1, 0};
    static constexpr int dx[] = {0, 1, 0, -1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dimY = mat.size();
        int dimX = mat[0].size();
        vector<vector<int>> dis(dimY);
        queue<pair<int, int>> q;
        vector<bool> vis(dimY * dimX, false);
        for(int i = 0; i < dimY; i++) {
            dis[i].resize(dimX, 0);
        }
        for(int i = 0; i < dimY; i++) {
            for(int j = 0; j < dimX; j++) {
                if(mat[i][j] == 0) {
                    q.emplace(i, j);
                    vis[i * dimX + j] = true;
                }
            }
        }
        while(!q.empty()){
            auto [y, x] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newY = y + dy[i];
                int newX = x + dx[i];
                if(newX >= 0 && newX < dimX && newY >= 0 && newY < dimY) {
                    if(vis[newY * dimX + newX] == false) {
                        dis[newY][newX] = dis[y][x] + 1;
                        q.emplace(newY, newX);
                        vis[newY* dimX + newX] = true;
                    }
                }
            }
        };
        return dis;
    }
};
// @lc code=end

