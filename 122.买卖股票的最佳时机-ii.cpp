/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* DP O(n) O(1)*/
        int n = prices.size();
        int dp0 = 0;
        int dp1 = -prices[0];
        for(int i=1; i<n; ++i){
            int newdp0 = max(dp0, dp1 + prices[i]);
            int newdp1 = max(dp1, dp0 - prices[i]);
            dp0 = newdp0;
            dp1 = newdp1;
        }
        return dp0;
    }
};
// @lc code=end

