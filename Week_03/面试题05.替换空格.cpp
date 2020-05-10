/*
题目：
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."

限制：
0 <= s 的长度 <= 10000

解题思路：
1.根据空格数量，扩充字符串长度，每个空格，扩充两个字符；
2.把原字符串（扩充前）倒序组织到新字符串中，遇到空格插入相应字符；
note：特殊情况，没有空格，返回原字符串
*/

class Solution {
public:
    string replaceSpace(string s) {
        int l1 = s.length() - 1;
        for (int i = 0; i <= l1; i++) {
            if (s[i] == ' ') {
                s += "00";
            }
        }
        int l2 = s.length() - 1;
        if (l2 <= l1) {
            return s;
        }
        for (int i = l1; i >= 0; i--) {
            char c = s[i];
            if (c == ' ') {
                s[l2--] = '0';
                s[l2--] = '2';
                s[l2--] = '%';
            } else {
                s[l2--] = c;
            }
        }
        return s;
    }
};