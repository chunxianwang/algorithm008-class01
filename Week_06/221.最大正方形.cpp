/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
/**
 * 和64题类似，动态规划：
 * 状态定义：dp[i][j]表示以(i,j)为右下角，且只包含1的正方形的变长最大值；
 * 状态转移：
 * 如果该位置的值是0，则 dp(i,j)=0，因为当前位置不可能在由1 组成的正方形中；
 * 如果该位置的值是1，则 dp(i,j) 的值由其上方、左方和左上方的三个相邻位置的
   dp 值决定。具体而言，当前位置的元素值等于三个相邻位置的元素中的最小值加1；
 * 时间复杂度O(M*N)
 * 
**/
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows==0) return 0;
        int columns = matrix[0].size();
        if (columns==0) return 0;
        int maxDP = 0;
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i==0 || j==0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    maxDP = max(maxDP, dp[i][j]);
                }
            }
        }
        return maxDP*maxDP; 
    }
};
// @lc code=end

