/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rotate_alt(vector<int> &nums, int k)
    {
        int n = nums.size(), m = gcd(n, k), tmp, idx;
        for (int i = 0; i < m; ++i)
        {
            idx = i;
            tmp = nums[i];
            do
            {
                swap(tmp, nums[(idx += k) %= n]);
            } while (idx != i);
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        reverse(nums.begin(), nums.end());
        vector<int>::iterator ptr = nums.begin() + (k % nums.size());
        reverse(nums.begin(), ptr);
        reverse(ptr, nums.end());
    }
};

static uint8_t acc = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// @lc code=end
