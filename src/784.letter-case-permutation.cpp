/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<string> result;
    string path;
    int n;
    void backtrace(string &s, int startIdx)
    {
        if (path.length() == n)
        {
            result.push_back(path);
            return;
        }
        char ch = s[startIdx];
        path.push_back(ch);
        backtrace(s, startIdx + 1);
        path.pop_back();
        if('a' <= ch && ch <= 'z') {
            path.push_back(ch + 'A' - 'a');
            backtrace(s, startIdx + 1);
            path.pop_back();
        }
        else if('A' <= ch && ch <= 'Z') {
            path.push_back(ch + 'a' - 'A');
            backtrace(s, startIdx + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCasePermutation(string s)
    {
        n = s.size();
        backtrace(s, 0);
        return result;
    }
};
// @lc code=end
