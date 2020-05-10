/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 * 解题思路：
 * 紧扣前序列定义，根-左-右；中序定义，左-根-右
 * 根据前序第一个节点（根节点）匹配到中序的根节点，把中序分为左子树和右子树，
 * 那么就得到了左右子树的长度，再返回到前序，以左右子树的根节点为起始，重复执行上述过程。
 * 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        TreeNode* root = new TreeNode(preorder[ps]);
        root->left = NULL;
        root->right = NULL;
        int i = is;
        while(i<=ie && preorder[ps]!=inorder[i])
            ++i;
        int ll=i-is;
        int rl=ie-i;
        if(ll>0) {
            root->left = build(preorder, ps+1, ps+ll, inorder, is, is+ll-1);
        }
        if(rl>0) {
            root->right = build(preorder, ps+ll+1, pe, inorder, is+ll+1, ie);
        }
        return root;
    }
};
/*
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)
            return NULL;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie){
        //构建根节点
        TreeNode* root=new TreeNode(preorder[ps]);
        root->left=NULL;
        root->right=NULL;
        
        //在中序序列中寻找根节点
        int i=is;
        while(i<=ie&&preorder[ps]!=inorder[i])
            ++i;
        //i指向中序序列中根节点的位置
        int ll=i-is;//左子树的序列长度
        int rl=ie-i;//右子树的序列长度
        
        //构建左右子树        
        if(ll>0){
            root->left=build(preorder,ps+1,ps+ll,inorder,is,is+ll-1);
        }
        if(rl>0){
            root->right=build(preorder,ps+ll+1,pe,inorder,is+ll+1,ie);
        }
        return root;
        
    }
};
*/

