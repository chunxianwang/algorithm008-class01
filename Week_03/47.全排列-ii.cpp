/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
/*
和【46】全排列相比，这里数组中有重复元素，难点在于去重
前提背景：一个递归循环，或者叫做一个层次的递归循环，即代表创建数组中的某一位；
递进到下一层递归循环，即代表创建数组中的下一位。
去重原则：
1.在同一个递归循环中，不能在同一位置多次选择相同的数字。
2.而在不同的递归循环中，可以在不同的位置选择相同的数字。
*/
// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    void dfs(int len, vector<int>& nums, vector<int>& current, vector<bool>& unused) {
        if (current.size() == len) {
            result.push_back(current);
            return;
        }
        for (int i=0; i<len; i++) {
            if (unused[i]) {
                if(i>0 && nums[i] == nums[i-1] && unused[i-1]) {//去重，这里unused[i-1]，确保i-1分支的递归已经结束
                    continue;
                }
                current.push_back(nums[i]);
                unused[i] = false;
                dfs(len, nums, current, unused);
                unused[i] = true;
                current.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};
        vector<bool> unused(len, true);
        vector<int> current;
        sort(nums.begin(), nums.end());
        dfs(len, nums, current, unused);
        return result;
    }
};
// @lc code=end

