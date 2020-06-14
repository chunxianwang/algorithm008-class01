/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int HmWeight = 0;
        for (int i=0; i<32; i++) {
            HmWeight += (n&1);
            n >>= 1;
        }
        return HmWeight;
    }
};
// @lc code=end

