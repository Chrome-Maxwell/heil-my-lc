/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {nums[0] * nums[0]};
        int pos = 0, neg = -1;
        for (int i : nums)
        {
            pos++;
            if (i >= 0)
            {
                pos--;
                break;
            }
            neg++;
        }
        vector<int> ans;
        while (neg >= 0 && pos < nums.size())
        {
            int a = nums[neg] * nums[neg], b = nums[pos] * nums[pos];
            if (a >= b)
            {
                ans.push_back(b);
                pos++;
            }
            else
            {
                ans.push_back(a);
                neg--;
            }
        }
        if (neg < 0)
            while (pos < nums.size())
            {
                ans.push_back(nums[pos] * nums[pos]);
                pos++;
            }
        else
            while (neg >= 0)
            {
                ans.push_back(nums[neg] * nums[neg]);
                neg--;
            }
        return ans;
    }
};
// @lc code=end
