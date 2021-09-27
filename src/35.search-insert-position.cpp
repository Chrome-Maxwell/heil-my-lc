/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
// 1. if res = 0 and nums[res] > target, then 
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid; 
        while(l != r) {
            int mid = l + (r - l)/2;
            // if nums[mid] > target, mid still needs to be considered. if nums[mid]
            if(nums.at(mid) == target) return mid;
            else if(nums.at(mid) > target) {
                if(mid == 0 || nums.at(mid - 1) < target ) return mid;
                else r = mid;
            }
            else {
                if(mid == nums.size() - 1 || nums.at(mid + 1) >= target) return mid + 1;
                else l = mid + 1;
            }
        }
        return nums.at(nums.size() - 1) >= target ? r : r + 1;
    }
};
// @lc code=end

