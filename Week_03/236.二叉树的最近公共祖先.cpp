/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
public:
#if 1
/*
递归：
递归终止条件：如果当前节点为空或p或q，返回当前节点
递归下探到下一层，遍历左子树，返回左子树是空，或是p或是q
递归下探到下一层，遍历右子树，返回右子树是空，或是p或是q
处理当前层逻辑，当前层如果左和右子树中都找到了p和q，返回root（祖先节点）
处理当前层逻辑，当前层如果只有左或右子树找到了p或q，返回相应子树

*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
#endif 
};
// @lc code=end

