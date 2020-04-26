/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#if 0
    //递归法
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL) {
            postorderTraversal(root -> left);
            postorderTraversal(root -> right);
            ans.push_back(root -> val);
        }
        return ans;
    }
#endif

#if 1
    /*
    后序遍历用前序遍历（#145题）相似的方法，后序遍历与前序遍历对称，遍历完成后把结果进行逆序处理
    伪代码：
    枚举更新根节点，来自栈中暂存的各级左子树（前序是右子树）
        枚举更新根节点，来自上次循环中根节点的右子树（前序是左子树）
            输出根节点的值；
            栈中暂存左子树（前序是右子树）
        根节点指向右子树（前序是左子树）
    根节点指向栈顶暂存的左子树（前序是右子树），弹栈顶；
    结果序列逆序
    */
    vector<int> postorderTraversal(TreeNode* root) {

        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || !S.empty()){
            while(rt){
                S.push(rt->left);
                v.push_back(rt->val);
                rt = rt->right;
            }
            rt = S.top();S.pop();
        }
        reverse(v.begin(), v.end());
        return v;      
    }
#endif
};
// @lc code=end

