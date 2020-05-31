/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
/*
暴力法：
枚举子序列，任意点开始，其后任意点结束，求所有子序列的最大值；时间复杂O(n^2);
即使做了优化，子序列以正数开始，以正数结束，时间复杂度亦然是O(n^2)；

DP思路：
  a. 分治（子问题） max_sum[i] = max(max_sum[i-1],0) + a[i];  当前元素自身最大，或包含之前最大子序列和的最大
  b. 状态数组定义：f[i]
  c.DP方程：f[i] = max(f[i-1],0) + a[i]

1.dp问题，公式为：dp[i] = max(nums[i], nums[i]+dp[i-1]);
2.最大子序列和 = 当前元素自身最大，或包含之前后最大；

*/

// @lc code=start
#if 0
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result;
        int numsSize = int(nums.size());
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};
#endif
#if 1
// 不开辟新数组，在原数组上保存dp状态。
//由于nums是引用变量传入的值，这样操作会改变变量值，影响函数外面，不满足数据安全原则，因此不提倡这样做。
//总结一条编程规则：引用变量，尽量不要在原引用数据上赋值操作，在拷贝数据上操作更安全。
class Solution
{
public:
    int maxSubArray(vector<int> &nums) {
        int result;
        int n = nums.size();
        result = nums[0];
        for (int i=1; i<n; i++) {
            nums[i] = max(nums[i-1] + nums[i], nums[i]);
            result = max(result, nums[i]); 
        }
        return result;
    }
};

#endif
#if 0 
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result;
        int numsSize = int(nums.size());
        //因为只需要知道dp的前一项，我们用int代替一维数组
        int dp(nums[0]);
        result = dp;
        for (int i = 1; i < numsSize; i++)
        {
            dp = max(dp + nums[i], nums[i]);
            result = max(result, dp);
        }

        return result;
    }
};
#endif

// @lc code=end

