/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, n = numbers.size(), r = n - 1;
        while (l < r)
        {
            if (numbers.at(l) + numbers.at(r) == target)
            {
                return {l + 1, r + 1};
            }
            else if (numbers.at(l) + numbers.at(r) < target)
                l++;
            else
                r--;
        }
        return {}; // ground case.
    }
};
// @lc code=end
