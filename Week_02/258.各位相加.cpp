/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 * 每日打卡
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
#if 0
        //循环暴力法
        int sum = 0;
        while (num >= 10) {
            sum = 0;
            while(num) {
                int tmp = num%10;
                sum += tmp;
                num /= 10;
            }
            num = sum;
        }
        return num;
#endif
#if 1
        //时间复杂度为O(1)的方法
        if(num != 0 && num % 9 == 0) return 9;
        else return num % 9;
#endif

    }
};
// @lc code=end

