/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
	// 判断是否是字符的方法 
    bool isAlpha (char c) {
        return (c >= 'A' && c <= 'Z') || (c >='a' && c <= 'z');
    }
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.size() - 1;
        while (left < right) {
            if (!isAlpha(S[left])) {
                left++;
            } else if (!isAlpha(S[right])) {
                right--;
            } else {
                swap (S[left], S[right]);
                left++;
                right--;
            }
        }
        return S;
    }
};
// @lc code=end

