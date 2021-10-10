/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        string::iterator l = s.begin(), r = l;
        while (r != s.end())
        {
            while (r != s.end() && *r != ' ')
                ++r;
            reverse(l, r);
            if (r != s.end())
                l = ++r; // prevent heap buffer overflow.
        }
        return s;
    }
};
// @lc code=end
