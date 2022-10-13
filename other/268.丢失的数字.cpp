/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(const int& num : nums)
            res ^= num;
        for(int i=1; i<=nums.size(); ++i)
            res ^= i;
        return res;
    }
};
// @lc code=end

