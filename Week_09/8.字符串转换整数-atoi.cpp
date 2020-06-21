/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)-状态机
 */
/*
参考自官方题解，练习使用状态机
*/

// @lc code=start
#include<unordered_map>
#include<vector>
using namespace std;
class Automation {
    string state = "start";
    unordered_map<string, vector<string>> table = {              //用map定义状态机转换规则
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int get_col(char c) {                       //状态机转换条件
        if (isspace(c)) return 0;               //空字符    字符函数，判断空字符
        if (c == '+' or c == '-') return 1;     //符号字符
        if (isdigit(c)) return 2;               //数组字符  字符函数，判断数字字符
        return 3;                               //其它字符
    }
public:
    int sign = 1;        //符号
    long long ans = 0;   //数值

    //对数字状态和符号状态进行处理
    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {             
            ans = ans*10 + (c - '0');
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);   //处理溢出
        } else if (state == "signed") {
            sign = c == '+' ? 1 : -1;           //处理符号
        }
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automation automation;
        for (char c : str) {                //遍历每个字符，触发状态机的状态间转换，以及处理数字状态和符号状态
            automation.get(c);
        }
        return automation.sign * automation.ans;
    }
};
// @lc code=end