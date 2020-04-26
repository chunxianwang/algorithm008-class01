/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include<vector>
using namespace std;
class Solution {
public:
#if 0
/*
递归法
*/
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL) {
            inorderTraversal(root -> left);
            ans.push_back(root -> val);
            inorderTraversal(root -> right);
        }
        return ans;
    }
#endif
    /*
    栈迭代方法思路：
    中序遍历
    每到一个节点 A，因为根的访问在中间，将 A 入栈。
    然后遍历左子树，接着访问 A，最后遍历右子树。
    在访问完 A 后，A 就可以出栈了。因为 A 和其左子树都已经访问完成。
    伪代码：
    初始化根节点
    枚举更新根节点，来自栈中暂存各级根节点的右子树
        枚举更新根节点，来自上次循环中根节点的左子树
            栈中暂存右子树；
        根节点指向当前根的左子树
    根节点指向栈顶暂存根节点的右子树，弹栈顶；
    输出根节点的值；
    更新根节点为栈中弹出根节点的右子树
    */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || !S.empty()){
            while(rt){
                S.push(rt);
                rt = rt->left;
            }
            rt = S.top();S.pop();
            v.push_back(rt->val);
            rt = rt->right;
        }
        return v;        
    }




};
// @lc code=end

