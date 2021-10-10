/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<int> vis;
    int n;
    void backtrace(vector<int>& nums) {
        int size = path.size();
        if(size == n) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]==true) continue;
            path.push_back(nums[i]);
            vis[i] = true;
            backtrace(nums);
            path.pop_back();
            vis[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vis.resize(n, false);
        backtrace(nums);
        return result;
    }
};
// @lc code=end

