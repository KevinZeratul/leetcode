/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        /* 第123题的推广 */
        int n = prices.size();
        if(!n || !k) return 0;
        vector<int> buy(k, -prices[0]);
        vector<int> sell(k, 0);
        for(int i=1; i<n; ++i){
            for(int j=0; j<k; ++j){
                if(j == 0){
                    buy[j] = max(buy[j], -prices[i]);
                    sell[j] = max(buy[j] + prices[i], sell[j]);
                }
                else{
                    buy[j] = max(buy[j], sell[j-1] - prices[i]);
                    sell[j] = max(buy[j] + prices[i], sell[j]);
                }
            }
        }
        return sell[k-1]; 
    }
};
// @lc code=end

