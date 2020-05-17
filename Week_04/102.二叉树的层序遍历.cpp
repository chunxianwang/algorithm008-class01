/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//队列暂存下层信息，利用其先进先出特点
#include<vector>
using namespace std;

class Solution {
#if 0
/*
BFS,用队列实现。根节点放入队列，在队列取出根节点的同时，把根节点的子节点分别放入下一层；
直到队列中当前层根节点被完全访问，再访问队列中下一层根节点
*/
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while (!q.empty()) {
            vector<int> vec;
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* tmp = q.front(); q.pop();
                vec.emplace_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            ans.emplace_back(vec);
        }
        return ans;
    }
#endif
#if 1
/*
DFS，
*/
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        addVector(root, 0);
        return res;
    }
    void addVector(TreeNode* root, int level) {
        if(root == NULL) return;
        if(res.size() == level) res.resize(level+1);//第一次访问当前层（不是return回到当前层），那就在数组中扩充放置下一层数据的容量
        res[level].push_back(root->val);
        addVector(root->left, level+1);
        addVector(root->right, level+1);
    }
#endif
};
// @lc code=end

