/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
/*
和77题【组合】类似，组合仅把不同元素放在一起成组，不考虑元素中的顺序；
而排列，相同的一组元素的不同顺序组合也需要被包含到最终结果里面。

最朴素的思路是：深度遍历，生成k叉树，
只需要保证递进到下一层时，不再使用已经用过的元素。
具体就是，用一个和nums相同尺寸的数组，标记nums中的元素是否访被使用过。

重点解读交换法：
首次调用dfs（第一层递归），可以实现nums中各个元素交换到begin = 0这一位上。
如把1交换到1上，如1号分支，1和1交换，可以生成{1,x,x}数组，
如2号分支，1和2交换，可以生成{2,x,x}数组，
如3号分支，1和3交换，可以生成{3,x,x}数组。
但是第一层递归，不会立刻把上述几个分支都生成完，而是基于深度遍历原则，先进入下一层递归，即长出下一层的树。

注意：在2号分支上，继续长下一层分支时，是基于{2，1，3}数组进行处理。
*/

// @lc code=start
class Solution {
#if 1
//朴素思路，用一个新数组标记是某元素未被使用过
private:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, vector<int>& current, vector<bool>& unused, int len) {
        if (current.size() == len) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (unused[i]) {
                current.push_back(nums[i]);
                unused[i] = false;
                dfs(nums, current, unused, len);
                unused[i] = true;
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return {};
        else {
            vector<bool> unused(len, true);
            vector<int> current;
            dfs(nums, current, unused, len);
            return result;
        }
    }
#endif

#if 0
//交换的方法
private:
    vector<vector<int>> res;
    void dfs(int begin, int end, vector<int>& nums) {
        if (begin == end) {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i <= end; i++) {
            swap(nums[i], nums[begin]);
            dfs(begin+1, end, nums);
            swap(nums[i], nums[begin]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0, nums.size()-1, nums);
        return res;
    }
#endif

};
// @lc code=end

