/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 * 两种解题思路，
 * 假设n=3
 * 1.在6个位置上，枚举左右括号组合，有2^6种，枚举完成后再从这些所有组合里面选出有效的组合
 * 2.还是在每个位置上枚举可能的括号组合情况，在每个位置上进行枚举时，判断是否有效，如果有效，继续下一个位置，否则停止枚举。
 * 
 * 穷举能解决的问题，可以形象地看成是k叉树的生长过程。这里左右括号形状，因此k=2
 * 
 * 典型的递归模板示例
 */

// @lc code=start
class Solution {
#if 0
private:
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        //递归标准过程1:递归终止条件，树满就停止
        if (cur.size() == n*2) {   
            ans.push_back(cur);
            return;
        }
        //左子树生长
        if (open < n) {          //是否允许左子树生长的判断条件   
            cur.push_back('(');  
            backtrack(ans, cur, open+1, close, n);  //递归标准过程3:下探到下一层，把当前层状态带入到下一层
            cur.pop_back();      //递归标准过程4:清理当前层状态，为了右子树使用一个进入当前层的“干净”状态
        }
        //右子树生长
        if (close < open) {      //是否右子树允许生长的判断条件
            cur.push_back(')');
            backtrack(ans, cur, open, close+1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
#endif
#if 1
//相同思路，优化代码
//优化点2个
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        addingpar(ans, "", n, 0); //优化点1: 直接传入空string，不再声明一个string变量
        return ans;
    }
private:
    //优化点2: 定义n和m，分别是当前可添加左、右括号的数量
    void addingpar(vector<string>& ans, string current, int n, int m) {
        if(n == 0 && m == 0) {
            ans.push_back(current);
            return;
        }
        if(m > 0) addingpar(ans, current+")", n, m-1);
        if(n > 0) addingpar(ans, current+"(", n-1, m+1);
    }
#endif
};
// @lc code=end

