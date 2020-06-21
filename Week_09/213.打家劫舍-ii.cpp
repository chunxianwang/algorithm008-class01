/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II-动态规划
 */

// @lc code=start
//和198题统一的写法
//只是因为环形导致的特殊情况，这里考虑两种情况：第一个偷，最后一个不偷；第一个不偷，最后一个偷；
#include<vector>
using namespace std;
class Solution {
private:
    int robRange(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        vector<vector<int>> dp (end-start+1, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[start];
        for (int i = 1; i<=end-start; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = nums[start+i] + dp[i-1][0];
        }
        return max(dp[end-start][0], dp[end-start][1]);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int rob_first_nolast = robRange(nums, 0, n-2);
        int rob_nofirst_last = robRange(nums, 1, n-1);
        return max(rob_first_nolast, rob_nofirst_last);
    }
};
// @lc code=end

