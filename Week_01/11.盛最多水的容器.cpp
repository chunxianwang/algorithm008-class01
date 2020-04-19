/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        int maxVolum = 0;
        while (leftIndex < rightIndex) {
            maxVolum = max(maxVolum, (rightIndex - leftIndex) * min(height[leftIndex], height[rightIndex]));
            if (height[leftIndex] < height[rightIndex]) {
                leftIndex++;
            } else {
                rightIndex--;
            }
        }
        return maxVolum;
    }
};
// @lc code=end

