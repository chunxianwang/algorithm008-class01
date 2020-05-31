/* 
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

/*
关键在于题目要求时间复杂度为O(logN)
显然从前往后的暴力搜索，时间复杂度O(N)不满足要求

题解：二分查找，左右半边，有一个是升序的，在其中查看是否有target，如果没有，则在另外一边；
反复执行上述二分查找过程
*/

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};
// @lc code=end

