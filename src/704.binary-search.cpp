/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid;
        while (l != r)
        {
            mid = l + (r - l) / 2;
            if (nums.at(mid) == target)
                return mid;
            else if (nums.at(mid) > target)
                r = mid;
            else
                l = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
