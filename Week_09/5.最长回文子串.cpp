/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
/*
注意是子串，不是[516]最长回文子序列，子串是连续的字符，子序列却可以不连续

状态定义dp[i][j]，从i到j的子串是回文子串，置1，否则置0

状态转移方程：
dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
即[i][j]内部包着的子串是回文串，且最外层的s[i]和s[j]相等，就置1；
*/

#include<vector>
using namespace std;

// @lc code=start
#if 0
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (l==0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }
                if (dp[i][j] && l+1 > ans.size()) {
                    ans = s.substr(i, l+1);
                }
            }
        }
        return ans;  
    }
};
#endif
#if 1
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp (n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (l == 0) dp[i][j] = 1;
                else if (l == 1) dp[i][j] = (s[i] == s[j]);
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l+1);
                }
            }
        }
        return ans;
    }
};

#endif

// @lc code=end

