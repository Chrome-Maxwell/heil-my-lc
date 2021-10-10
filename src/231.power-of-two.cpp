/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n <= 0) return false;
//         return n==1 ? true :  (!(n & 1)) && isPowerOfTwo(n >> 1);
//     }
// };
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && ((n & n - 1) == 0); // that's cool...
    }
};
// @lc code=end
