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


class Solution {
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
};
// @lc code=end

