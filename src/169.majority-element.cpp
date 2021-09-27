/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ans = nums[0];
        for(auto i : nums) {
                ans == i? cnt++ : cnt--;
            if(cnt==0) {
                ans = i;
                cnt = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

