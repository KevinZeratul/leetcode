/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // x^x=0 x^0=x
        int ans = 0;
        for(const int &num : nums)
            ans ^= num;
        return ans;
    }
};
// @lc code=end

