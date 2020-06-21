/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍-动态规划
 */
/*
DP：
  a. subproblems: 截止到当前房间的最高金额，等于之前偷到的金额，+ 当前房间的金额；
                  但是存在不能连续偷两个房间的问题，那么当前房间也存在两种状态，偷或不偷

  b. dp array状态数组：dp[i][0]，第i个房间不偷时，得到的最高金额； dp[i][1]，第i个房间偷时，得到的最高金额。
  c. 动态方程：  dp[i][1] = dp[i-1][0] + nums[i]; //第i个房间偷，那么i-1个房间，肯定不偷
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);//第i个房间不偷，那么i个房间的金额等于（i-1个房间可能偷，也可能不偷所得金额的最大值）
*/

// @lc code=start
#include<vector>
using namespace std;
#if 0
class Solution {
public:
    int rob(vector<int>& nums) {
       int n =nums.size();
       if(n == 0) return 0;
       vector<vector<int>> dp(n, vector<int>(2)); //二维数组
       dp[0][0] = 0; 
       dp[0][1] = nums[0];
       for (int i=1; i<n; i++) {
           dp[i][0] = max(dp[i-1][1], dp[i-1][0]);  //当前房间不偷，等于前一个房间偷或不偷的最大value；
           dp[i][1] = nums[i] + dp[i-1][0];         //当前房间偷，等于当前房间value + 前一个房间不偷的最大value；
       }
       return max(dp[n-1][0], dp[n-1][1]);
    }
};
#endif



/*
DP：  //优化，用一维数组
  a. subproblems: 截止偷到当前房间的最高金额，等于之前偷到的金额，+ 当前房间的金额；
                  偷到当前房间的最高金额，等于前一个房间的最高金额，或者当前房间的最高金额+前&前房间的最高金额；
  b. dp array状态数组：dp[i]，到第i个房间时，偷到的最高金额；
  c. 动态方程：  dp[i]= max(dp[i-1], (dp[i-2]+nums[i]));
*/
#if 0
class Solution {
public:
    int rob(vector<int>& nums) {
       int n =nums.size();
       if(n == 0) return 0;
       if(n == 1) return nums[0];
       vector<int> dp(n); //二维数组
       dp[0] = nums[0]; 
       dp[1] = max(nums[0], nums[1]);
       for (int i=2; i<n; i++) {
           dp[i] = max(dp[i-2]+nums[i], dp[i-1]);  //当前房间不偷，等于前一个房间偷或不偷的最大value；
       }
       return dp[n-1];
    }
};
#endif

#if 0
//练习区
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dp (n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
#endif

#if 1
//练习区
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
        if (nums.size() == 0) return 0;
        return robRange(nums, 0, nums.size()-1);
    }
};
#endif

// @lc code=end

