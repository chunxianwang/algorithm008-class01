/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
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
#if 0
//递归法
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        if (root != NULL) {
            helper(root, 0);
        }
        return res;
    }
    void helper(Node* root, int level) {
        if(res.size() <= level) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        //遍历子树
        for (auto node : root->children) {
            helper(node, level+1);
        }
    }
#endif
#if 1
//迭代法
//枚举某一层的所有根时，把其所有子树存入队列，
//作为下次迭代时要枚举的所有根
vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            //一次迭代，枚举当前队列中存的所有根，
            //访问值，存入结果数组，
            //获取子树
            //弹出根
            //压入子树
            int n = q.size();
            vector<int> temp;
            while(n--){
                vector<Node*> child_node = (q.front())->children;
                temp.push_back((q.front())->val);
                q.pop();
                for(auto node : child_node){
                    if(node){
                        q.push(node);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
#endif


};
// @lc code=end

