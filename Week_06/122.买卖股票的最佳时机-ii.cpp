/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 0
    /*贪心算法
    注意同一天，不能买入又卖出，否则违规！
    从连续几天涨跌的情况看，分三类：
    1.涨跌交交替，有多个高峰和低谷，操盘原则：低谷买入，高峰卖出；
    2.持续上涨，每天买入和卖出，能获得总利润，可是操作违规；这样的操作和第一天买入，连续上涨最后一天卖出，拿到的总利润一样，且不违规；
    3.持续下跌，不买卖，不会产生亏损。
    思路是这个思路，具体操作就是，贪心算法，每相邻两个交易日，如果有上涨，计入总利润；否则总利润维持不变。
*/
        int profit = 0;
        for (int i=1; i < prices.size(); i++) {
            profit += max(prices[i]-prices[i-1], 0);
        }
        return profit;
#endif
#if 0
    /*
    动态规划：二维数组
    */
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i=0; i<n; i++) {
            if(i == 0) {
                dp[i][1] = 0 -prices[i];
                dp[i][0] = 0;
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);  //之前买入过，或者是之前的卖了（不持有），今天买入。
        }
        return dp[n-1][0];
#endif
#if 1
        int n = prices.size();
        if (n==0) return 0;
        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];
        for (auto price : prices) {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + price);
            dp_i_1 = max(dp_i_1, tmp-price);
        }
        return dp_i_0;
#endif
    }
};
// @lc code=end

