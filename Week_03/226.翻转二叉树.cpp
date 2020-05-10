/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
class Solution {
#if 0
//递归法，第一种写法，新写一个回归函数
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
private:
    void dfs(TreeNode* root) {
        if(root) {     //递归终止条件
            swap(root->left, root->right);  //处理当前层逻辑
            dfs(root->left); //下探到下一层
            dfs(root->right);//下探到下一层
        }
    }
#endif

#if 1
//递归法，第二种写法，不另写一个回归函数，直接用“主”函数回归
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
#endif


};
// @lc code=end

