/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

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
注意仅仅是根节点大于左子节点，以及根节点小于右子节点；
还要满足根节点，大于所有左子树，以及根节点小于所有右子树
因此遍历树的每一个节点时，要保留节点的上界与下界
*/
class Solution {

#if 1
/*
方法一：基于边界点递归法，
本质上是一个中序遍历，遍历过程中，得到判断是否搜索二叉树的结论

递归时，要特别注意，带入到下一层的内容（状态和待处理参数）
边界，就是下探到下一层时带入的当前层的状态（逻辑处理更新过的）
*/
private:
    bool fun(TreeNode* root, long low, long high) {
        if(root == NULL) return true;//递归终止条件
        long num = root->val;  //处理当前层逻辑
        if(num <= low || num >= high) return false; //处理当前层逻辑，同时也是终止递归条件之一
        return fun(root->left, low, num) && fun(root->right, num, high); //下探到下一层
        //下探到左子树，就把根的值，作为上边界；下探到右子树，就把根的值，作为下边界
    }

public:
    bool isValidBST(TreeNode* root) {
        return fun(root, LONG_MIN, LONG_MAX);
    }
#endif

};

// @lc code=end

