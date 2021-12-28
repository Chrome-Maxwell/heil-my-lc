/*
 * @lc app=leetcode id=1995 lang=cpp
 *
 * [1995] Count Special Quadruplets
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    n = nums.size();
    cnt = 0;
    backtrace(nums, 0);
    return cnt;
  }

private:
  int n;
  int cnt;
  vector<int> path;
  void backtrace(vector<int> &nums, int beg) {
    if (path.size() == 3) {
      int sum = nums[path[0]] + nums[path[1]] + nums[path[2]];
      for (; beg < n; beg++) {
        if (sum == nums[beg])
          cnt++;
      }
      return;
    }
    for (int i = beg; i < n; i++) {
      path.push_back(i);
      backtrace(nums, i + 1);
      path.pop_back();
    }
  }
};
// [28,8,49,85,37,90,20,8] -> 1
// @lc code=end
