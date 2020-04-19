/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 * 读题注意关键词：排序数组，原地，不考虑数组中超出新长度后面的元素
双指针：非重复元素指针，遍历指针，注意遍历指针从指向第二个数组元素开始；
TC:O(N)
SC:O(1)
 * 
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[index]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
};
// @lc code=end

