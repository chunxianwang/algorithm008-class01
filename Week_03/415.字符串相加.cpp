/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

/*

*/

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int ln1 = num1.length() - 1;
        int ln2 = num2.length() - 1;
        int carry = 0;
        string ans = "";
        while (carry || ln1 >= 0 || ln2 >=0) {
            int x = ln1 < 0 ? 0 : num1[ln1--] - '0';
            int y = ln2 < 0 ? 0 : num2[ln2--] - '0';
            ans.insert (0,1,(x+y+carry)% 10 + '0'); 
            //不同于push_back，insert 从string最左端插入字符。
            carry = (x+y+carry)/10;
        }
        return ans;
    }
};
// @lc code=end

