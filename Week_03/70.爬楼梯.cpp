/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:

int climbStairs(int n) {

#if 1
//动态规划，从a->z，那么一步步来，先到b、c、d...
//大问题分解为小问题，并且利用小问题得到的中间结果
     vector<int>steps(n+1,0);
     steps[0]=1;
     steps[1]=1;
     for(int i=2;i<=n;i++)
     {
         steps[i]=steps[i-2]+steps[i-1];
     }
     return steps[n];
}
#endif
};
// @lc code=end

