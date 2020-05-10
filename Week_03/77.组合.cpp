/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
/*
采用dfs遍历二叉树，
在二叉树的尾部终端节点得到想要的数组，
需要考虑避免数组重复，以及二叉树遍历时需要剪去一些不必要的枝桠。
*/

// @lc code=start
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    void dfs(int n, int k, int start, vector<int>& path) {
        //递归终止条件，得到一个长度为k的数组，终止时，得到结果中的一个元素；
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        //处理当前层逻辑，同时进入下一层
        //把不同元素放入数组，包括放入-push_back，和弹出-pop_back;
        for (int i = start; i <= n-(k-path.size()) + 1; ++i) {
            path.push_back(i);
            //进入到下一层
            dfs(n, k, i+1, path);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        if (n<=0 || k<=0 || k>n) return res;
        vector<int> path;
        dfs(n, k, 1, path);
        return res;
    }
};
// @lc code=end

