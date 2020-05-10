/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
/*
递归法：
针对当前层，存在3种情况：
1.当前root为空，那么跳出递归，且返回深度值0；
2.当前root左或右子树为空，那么也可以结束递归，
  返回不为空的子树深度+1（操作技巧，其中一个是0，那么可以把两者相加再+1）
3.当前root的左、右子树都不是空，那么返回左右子树的较小深度+1
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int m1 = minDepth(root->left);
        int m2 = minDepth(root->right);
        return (root->left == NULL || root->right == NULL) ? m1+m2+1 : min(m1, m2) + 1;
    }
};
// @lc code=end

