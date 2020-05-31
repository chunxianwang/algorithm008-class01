/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
/*
买卖股票问题，定义状态：
dp[i][k][b]第i天，买入k次，收上有股票或无股票时的利润
如果不考虑买入次数，则不需要定义k维度。
注意只能买入一次股票，就是k<=1
*/

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 0
        //定义状态数组的写法    
        int n =prices.size();
        if (n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(2,0));
        for (int i=0; i<n; i++) {
            if(i==0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            
            dp[i][1] = max(dp[i-1][1], -prices[i]);  //之前买入过，或者是之前没买过（利润为0）今天买入。
        }
        return dp[n-1][0];
#endif
#if 1
//降低空间复杂度的写法
//注意状态转移方程，新状态只和相邻状态相关，因此可以把数组改为变量，降低空间复杂度。
        int n = prices.size();
        if (n==0) return 0;
        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];
        for (auto price : prices) {
            dp_i_0 = max(dp_i_1+price, dp_i_0);
            dp_i_1 = max(dp_i_1, -price);
        }
        return dp_i_0;
#endif
    }
};
// @lc code=end

