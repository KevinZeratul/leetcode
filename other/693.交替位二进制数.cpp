/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long a = (n >> 1) ^ n;
        return (a & (a+1)) == 0;
    }
};
// @lc code=end

