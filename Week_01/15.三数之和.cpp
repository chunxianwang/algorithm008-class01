/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<vector>
using namespace std;
/*
解体思路：
三个指针，其中一个是枚举指针，另外两个是左右指针；
这三个指针都要考虑数组中元素重复的情况

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i < n-2; i++) {
            if (nums[i] > 0) break;  //加速循环
            int left = i + 1;
            int right = n - 1;
            if (i > 0 && nums[i] == nums[i-1]) continue; //枚举元素，数据重复
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[++left]);  //左指针元素，数据重复
                    while (left < right && nums[right] == nums[--right]);//右指针元素，数据重复
                }
            } 
        }
        return ans;
    }
};
// @lc code=end

