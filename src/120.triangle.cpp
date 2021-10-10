/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i].resize(i + 1, 0);
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if (j == i)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        int result = dp[n - 1][0];
        for(int i = 0; i < n; i++) {
            result = min(result, dp[n - 1][i]);
        }
        return result;
    }
};
// @lc code=end
