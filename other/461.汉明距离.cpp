/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int ans = 0;
        while(z){
            ans += z & 1;
            z >>= 1;
        }
        return ans;
    }
};
// @lc code=end

