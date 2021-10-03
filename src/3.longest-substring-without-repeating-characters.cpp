/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> tbl(1 << 8, -1);
        int l = 0, ans = 0;
        for (auto i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (tbl[ch] != -1)
                l = max(l, tbl[ch] + 1);
            tbl[ch] = i;
            ans = max(i - l + 1, ans);
        }
        return ans;
    }
};
// @lc code=end
