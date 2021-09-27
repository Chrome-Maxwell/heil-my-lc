/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};
// @lc code=end
