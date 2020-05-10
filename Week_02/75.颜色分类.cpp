/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
  public:
#if 0
  void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
 #endif
#if 1
void sortColors(vector<int>& nums) {
    int p0 = 0, curr = 0;
    int p2 = nums.size() - 1;
    while (curr <= p2)
    if(nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
    } else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);//不是curr++
    }
    else curr++;
}
#endif
};
// @lc code=end