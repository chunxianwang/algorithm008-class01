/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

//从后往前，找到不是空格的单词，开始计数。

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() < 1) return 0;
        int i = s.size()-1;
        int ans = 0;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }
        return ans;
    }
};
// @lc code=end

