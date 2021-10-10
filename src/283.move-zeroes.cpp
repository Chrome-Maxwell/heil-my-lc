/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        vector<int>::iterator l = nums.end(), r;
        for (auto i = nums.begin(); i != nums.end(); ++i)
        {
            if (*i == 0)
            {
                l = i;
                break;
            }
        }
        if (l == nums.end())
            return;
        for (r = l + 1; r != nums.end(); ++r)
        {
            if (*r != 0)
            {
                swap(*l, *r);
                l++;
            }
        }
    }
};
// @lc code=end
