/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* 贪心 */
        int minprice = prices[0];
        int maxprofit = 0;
        for(int price : prices){
            maxprofit = max(maxprofit, price-minprice);
            minprice = min(minprice, price);
        }    
        return maxprofit;

    }
};
// @lc code=end

