/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
#if 1
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        Node* rt;
        if(root == NULL) return res;
        st.push(root);
        while (!st.empty()) {
            rt = st.top();
            st.pop();
            res.push_back(rt->val);
            int width = rt->children.size();
            for (int i = width-1; i >=0; --i) {
                st.push(rt->children[i]);
            }
        }
        return res;
     }
#endif
#if 0
    //递归法
    vector<int> res;
    vecot<int> preorder(Node* root) {
        if(root) {
            res.push_back(root->val);
            for(int i = 0; i < root->children.size(); i++) {
                preorder(root->children[i]);
            }
        }
        return res;
    }
#endif

};
// @lc code=end

