/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        //题目中描述的任务，有局部性，即判断局部括号是否闭合，
        //自然可以想到用栈来解决问题。
        /*
        具体思路：枚举字符串，
        如果属于左括号，入栈；
        如果属于右括号且和栈顶字符封闭，则出栈；
        其它，字符串不属于括号，或者属于右括号，但不与栈顶封闭，返回false，跳出枚举；
        枚举结束时，判断栈是否空，非空则返回false
        */
        unordered_map<char, int> m{{'(', 1}, {'{', 2}, {'[', 3}, {')', 4}, {'}', 5}, {']', 6}};
        stack<char> st;
        for (char c:s) {
            int flag = m[c];
            if(flag >=1 && flag<=3) st.push(c);
            else if (!st.empty() && m[st.top()] == (flag - 3)) st.pop();
            else return false;
        }
        if (!st.empty()) return false;
        return true;
    }
};
// @lc code=end

