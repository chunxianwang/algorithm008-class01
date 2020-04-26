/*week2-每日打卡覃超推荐-经典题
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
/*
思路一：字符串的局部性，可用栈或栈的思想
思路二：参考最佳题解，
初始化，跳过最外面的左括号，左括号计数初始为1，右为0
枚举字符串中的字符对左右括号进行计数；
    如果左右计数相等，把当前字符放入结果字符串ans；
    否则，不放入结果字符串，重新执行“初始化”过程，继续枚举字符；
枚举结束，返回ans。
*/
    string removeOuterParentheses(string S) {
        int L = 1, R = 0;
        string ans;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] == '(') L++;
            else R++;
            if (R != L) ans.push_back(S[i]);
            else {
                i++;
                L = 1;
                R = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

