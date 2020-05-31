/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n =nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int r=2; r<n; r++) {   //区间长度
            for (int i=0; i<n-r; i++) {      //i～k，左区间
                int j=i+r;               
                for (int k=i+1; k<j; k++) {  //k～j，右区间
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][n-1];
    }
}; 
// @lc code=end

