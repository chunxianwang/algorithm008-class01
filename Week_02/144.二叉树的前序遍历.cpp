/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include<stack>
using namespace std;
class Solution {
public:
    #if 0
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root != NULL) {
            ans.push_back(root -> val);
            preorderTraversal(root -> left);
            preorderTraversal(root -> right);
        }
        return ans;
    }
    #endif
    #if 0
    /*
    方法：迭代前序遍历
    本质上是用栈来模拟递归
    前序遍历：在根节点，输出值，访问左孩子，

    */
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* p = root;
        while(p || !st.empty()){
            while(p) {
                ans.emplace_back(p -> val);
                st.push(p);
                p = p ->left;
            }
            p = st.top(); st.pop();
            p = p -> right;
        }
        return ans;
    }
    #endif
    /*
    栈迭代方法思路：
    前序列遍历
    不断更新当前根节点，来源：初始化根节点，上次迭代中根节点的左子树，栈中的右子树
    伪代码：
    初始化根节点
    枚举更新根节点，来自栈中暂存的各级右子树
        枚举更新根节点，来自上次循环中根节点的左子树
            输出根节点的值；
            栈中暂存右子树；
        根节点指向左子树
    根节点指向栈顶暂存的右子树，弹栈顶；
    */
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || !S.empty()){
            while(rt){
                S.push(rt->right);
                v.push_back(rt->val);
                rt = rt->left;
            }
            rt = S.top();S.pop();
        }
        return v;        
    }
    /*问题延伸：
    后序遍历用前序遍历相似的方法，后序遍历与前序遍历对称，遍历完成后把结果进行逆序处理
    伪代码：
    枚举更新根节点，来自栈中暂存的各级左子树
        枚举更新根节点，来自上次循环中根节点的右子树
            输出根节点的值；
            栈中暂存左子树
        根节点指向右子树
    根节点指向栈顶暂存的左子树，弹栈顶；
    结果序列逆序
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || !S.empty()){
            while(rt){
                S.push(rt->left);
                v.push_back(rt->val);
                rt=rt->right;
            }
            rt=S.top();S.pop();
        }
        reverse(v.begin(), v.end());
        return v;      
    }
    */



    #if 0
    /*
    方法：迭代前序遍历
    */
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        stack<TreeNode*> st; 
        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            TreeNode* p = st.top(); st.pop();
            ans.emplace_back(p -> val);
            if(p ->right != NULL)
                st.push(p -> right);
            if(p ->left != NULL)
                st.push(p -> left);
        }
        return ans;
    }
    #endif

};
// @lc code=end

