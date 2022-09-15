/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        // 脑筋急转弯，题目转换为求[1, n]中的完全平方数个数
        // 为了避免开根号精度问题，+0.5
        return sqrt(n + 0.5);
        
    }
};
// @lc code=end

