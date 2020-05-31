/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
/*
第一步，定义dp状态；
       对于两个字符串的动态规划问题，都可以定义以两个字符串为边的
       二维数组dp[s1.size()][s2.size()]，这里数组中的元素dp[i][j]表示，
       对于s1[1,2,...i]和s2[1,2,...j]，他们的lcs长度是dp[i][j];
第二步，定义base case，
       定义第一行和第一列，这样可以很好支持第二行、列进行状态转移，（要用到第一行、列的状态）；
第三部，定义状态转移方程
       这是最难的一步，
       如果s1[i]==s2[j];dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
       如果s1[i]!=s2[j];dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1];
*/


// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
#if 0
//第一种写法
        int rows = text1.size();
        int columns = text2.size();
        if (rows==0 || columns==0) return 0;
        vector<vector<int>> dp(rows, vector<int>(columns,0));
        if (text1[0]==text2[0]) dp[0][0] = 1;
        for (int i=1; i<rows; i++) {
            dp[i][0] = dp[i-1][0];
            if (text1[i] == text2[0]) {
                dp[i][0] = 1;
            }
        }
        for (int j=1; j<columns; j++) {
            dp[0][j] = dp[0][j-1];
            if (text1[0] == text2[j]) {
                dp[0][j] = 1;
            }
        }
        for (int i=1; i<rows; i++) {
            for(int j=1; j<columns; j++) {
                if(text1[i]==text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[rows-1][columns-1];
#endif
#if 1
//第二种写法
//在dp table中增加了一行‘’ 和一列‘’，空字符串
        int rows = text1.size();
        int columns = text2.size();
        if (rows==0 || columns==0) return 0;
        vector<vector<int>> dp (rows+1, vector<int>(columns+1, 0));
        for (int i=1; i<=rows; ++i) {
            for (int j=1; j<=columns; ++j) {
                  dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), 
                        dp[i-1][j-1]+(text1[i-1] == text2[j-1])); //注意这里dp[i-1][j-1]+(text1[i-1]==text2[j-1])是一个整体
            }
        }
        return dp[rows][columns];
#endif
    }
};
// @lc code=end

