/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
#if 0
//正序，看是否能达到最后一个
        int reach = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(i > reach) {
                return false;
            }
            reach = max(i+nums[i], reach);
        }
        return true;
#endif
#if 1
//到序列，看是否能从第一个起始；
        int n = nums.size(), last = n - 1;
        for(int i=n-2; i>=0; i--) {
            if(i+nums[i] >= last) last = i;
        }
        return last == 0;
#endif
    }
};
// @lc code=end

