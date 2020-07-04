/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 1.数组倒序操作；
2.从后往前数，找到第一个非9的数字，对其➕1操作，并返回结果；找到这个非9数字之前的各个位置的9都置0；
3.如果没有找到非9数字，那么说明所有数都是9，就在数组末尾增加一位，置0，并把首位置1.
TC:O(n)
SC:O(1)
 */
// @lc code=start
#if 0
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
#endif
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
// @lc code=end

