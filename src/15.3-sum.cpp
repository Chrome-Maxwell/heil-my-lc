/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i < N - 2; ++i) {
            if(nums[i]>0) break;
            else if(i > 0 && nums[i]==nums[i - 1]) continue;
            else {
                int j = i + 1, k = N - 1;
                while(j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum > 0) --k;
                    else if(sum < 0) ++j;
                    else {
                        ans.push_back({nums[i], nums[j], nums[k]}); 
                        while(j < k && nums[j]==nums[j+1]) ++j;
                        while(j < k && nums[k]==nums[k-1]) --k;
                        ++j;
                        --k;
                        }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

