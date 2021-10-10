/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrace(int n, int k, int cur)
    {
        int size = path.size();
        if (size == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = cur; i <= n - (k - size) + 1; i++)
        {
            path.push_back(i);
            backtrace(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        backtrace(n, k, 1);
        return result;
    }
};
// @lc code=end
