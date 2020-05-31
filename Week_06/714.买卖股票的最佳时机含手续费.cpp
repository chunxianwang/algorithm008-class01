/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;
        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];
        for (auto price : prices) {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1+price - fee);
            dp_i_1 = max(dp_i_1, dp_i_0-price);
        }
        return dp_i_0;
    }
};
// @lc code=end

