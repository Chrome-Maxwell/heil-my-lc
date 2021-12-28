/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// class Solution { // single pointer
// public:
//     int removeElement(vector<int>& nums, int val) {
//         if(nums.empty()) return 0;
//         int p = nums.size() - 1;
//         while(p >= 0 && nums[p] == val) p--;
//         for(int i = 0; p >= 0 && i < p; ++i) {
//             if(nums[i] == val) {
//               while(p >= 0 && nums[p] == val) p--;
//               swap(nums[i], nums[p]);
//               while(p>= 0 && nums[p] == val) p--;
//             };
//         }
//         return p + 1;
//     }
// };
class Solution { // dual pointers
public:
  int removeElement(vector<int> &nums, int val) {
    int p1 = 0;
    for(int p2 = 0; p2 < nums.size(); p2++) {
      if(nums[p2] != val) {
        nums[p1++] = nums[p2];
      }
    }
    return p1;
  }
};
// @lc code=end

// special case: [0,1,2,3,3,0,4,2]\n2
// special case: [0,4,4,0,4,4,4,0,2]\n4