/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        else
        {
            vector<int> dp(n);
            dp[0] = nums[0];
            dp[1] = nums[1];
            dp[2] = nums[0] + nums[2];
            for (int i = 3; i < n; i++)
            {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
            }
            return max(dp[n - 1], dp[n - 2]);
        }
    }
};
// @lc code=end
