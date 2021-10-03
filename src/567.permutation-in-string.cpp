/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;
        vector<int> tbl_s1(26, 0);
        vector<int> tbl_s2(26, 0);
        int len_s1 = s1.length(), len_s2 = s2.length();
        int l = 0, r = len_s1 - 1;
        for (auto i = 0; i < len_s1; i++)
        {
            tbl_s1[s1[i] - 'a']++;
            tbl_s2[s2[i] - 'a']++;
        }
        while (r < len_s2)
        {
            bool found = true;
            for (int i = 0; i < 26; i++)
            {
                if (tbl_s1[i] != tbl_s2[i])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                return true;
            else
            {
                tbl_s2[s2[l] - 'a']--;
                l++;
                r++;
                if (r < len_s2)
                    tbl_s2[s2[r] - 'a']++;
            }
        }
        return false;
    }
};
// @lc code=end
