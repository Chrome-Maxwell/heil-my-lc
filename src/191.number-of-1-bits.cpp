/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return n > 0 ? (n & 1 ? 1 : 0) + hammingWeight(n >> 1) : 0;
    }
};
// @lc code=end
