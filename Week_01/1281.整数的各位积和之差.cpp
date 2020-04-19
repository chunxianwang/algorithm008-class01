/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
            while (n > 0) {
                int remainder = n%10;
                n = n/10;
                product = product * remainder;
                sum += remainder;
            }
        return (product - sum);

    }
};
// @lc code=end

