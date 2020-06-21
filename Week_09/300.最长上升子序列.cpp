/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列-动态规划
 */

#if 0
/*
思路，动态规划，关键是定义状态和状态转移方程
定义状态：从数组首部到第i元素的最长上升子序列的长度dp[i]；

状态转移方程：
遍历所有的i，求出以各个元素为终点的最长上升子序列，然后比较所有的dp[i]，求出最大值，即整个数组的最长上升子序列长度；

如何求dp[i]呢？
遍历0～i-1的数组元素，如果某个元素num[j]小于nums[i]，则dp[i] = max (dp[i], dp[j] + 1);
即等于以j为终点的最长上升子序列长度+1，或 dp[i]的较大值。

就是看看是否之前的所有子序列是否有可能加上num[i]这一个元素，组成一个更长的子序列。

！！！难点：
状态转移方程，隐藏在两个嵌套的遍历过程中；

记住！以当前遇元素结尾的最长子序列，可能是由之前一个最长子序列加上当前元素本身组成

时间复杂度O(N^2)，因为有两层嵌套遍历
*/

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i=0; i < n; i++) {
            dp[i] = 1;
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
#endif


// @lc code=end

