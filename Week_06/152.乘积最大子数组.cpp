/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
/*
和53题【最大子序列和】类似
PD思路：
  a.分治：当前元素最大乘积 是 前一个元素最大乘积乘以当前元素，或前一个元素最小乘积（负数）乘以以当前元素（负数），或当前元素自身；
  b.状态定义：dpmax[i]当前元素最大乘积，dpmin[i]当前元素最小乘积（负数）;
  c.DP方程：dpmax[i] = max(dpmax[i-1]*当前元素，dpmin[i-1]*当前元素，当前元素)；
           dpmin[i] = min(dpmax[i-1]*当前元素，dpmin[i-1]*当前元素，当前元素);
*/

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
#if 0
        int n = nums.size();
        vector<int> dpmin(n), dpmax(n);
        dpmin[0] = nums[0];
        dpmax[0] = nums[0];
        int result = dpmax[0];
        for (int i=1; i<n; i++) {
            dpmax[i] = max(dpmax[i-1]*nums[i], max(dpmin[i-1]*nums[i], nums[i]));
            dpmin[i] = min(dpmax[i-1]*nums[i], min(dpmin[i-1]*nums[i], nums[i]));
            result = max(result, dpmax[i]);
        }
        return result;
#endif
#if 1
//推荐～～～不用声明数组，节省空间的写法
        int n =nums.size();
        int dpmax = nums[0], dpmin = nums[0], result = nums[0];
        for (int i=1; i<n; i++) {
            int tmpmax = dpmax, tmpmin = dpmin;
            dpmax = max(tmpmax*nums[i], max(tmpmin*nums[i], nums[i]));
            dpmin = min(tmpmax*nums[i], min(tmpmin*nums[i], nums[i]));
            result = max(dpmax, result);
        }
        return result;

#endif
    }
};
// @lc code=end

