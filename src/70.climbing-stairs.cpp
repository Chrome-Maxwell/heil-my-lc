/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if(n == 1) return 1;
        int *dp = new int[n+1];
        int result;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        result = dp[n];
        delete [] dp;
        return result;
    }
};
// @lc code=end
