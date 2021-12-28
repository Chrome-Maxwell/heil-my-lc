/*
 * @lc app=leetcode id=1995 lang=cpp
 *
 * [1995] Count Special Quadruplets
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// class Solution {
// public:
//   int countQuadruplets(vector<int> &nums) {
//     n = nums.size();
//     cnt = 0;
//     backtrace(nums, 0);
//     return cnt;
//   }

// private:
//   int n;
//   int cnt;
//   vector<int> path;
//   void backtrace(vector<int> &nums, int beg) {
//     if (path.size() == 3) {
//       int sum = nums[path[0]] + nums[path[1]] + nums[path[2]];
//       for (; beg < n; beg++) {
//         if (sum == nums[beg])
//           cnt++;
//       }
//       return;
//     }
//     for (int i = beg; i < n; i++) {
//       path.push_back(i);
//       backtrace(nums, i + 1);
//       path.pop_back();
//     }
//   }
// };
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define re_(i, a, b) for (int i = (a); i < (b); ++i)
#define dwn(i, a, b) for (int i = (a); i >= (b); --i)
class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    int n = nums.size(), ans = 0, mx = *max_element(nums.begin(), nums.end());
    vector<vector<int>> dp(mx + 1, vector<int>(4));
    dp[0][0] = 1;
    rep(i, 1, n) {
      int v = nums[i - 1];
      ans += dp[v][3];
      dwn(j1, mx, v) { dwn(j2, 3, 1) dp[j1][j2] += dp[j1 - v][j2 - 1]; }
    }
    return ans;
  }
};
// [28,8,49,85,37,90,20,8] -> 1
// @lc code=end
