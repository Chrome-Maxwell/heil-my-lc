/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
// #include <bits/stdc++.h>
// using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = findLB(nums, target);
    int r = findUB(nums, target);
    if (l == -1 || r == -1)
      return {-1, -1};
    else if (r - l >= 0)
      return {l, r};
    else return {-1, -1};
  }

private:
  int findLB(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size();
    int res = -1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid; // the lower bound is in the left half interval
        res = mid;
      }
    }
    return res;
  }
  int findUB(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size();
    int res = -1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] <= target) {
        l = mid + 1; // the upper bound is in the right half interval
        res = mid;
      } else {
        r = mid;
      }
    }
    return res;
  }
};
// @lc code=end
