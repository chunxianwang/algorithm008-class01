/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
#if 0
    void moveZeroes(vector<int>& nums) {
        //方法一，问题拆解：计算有几个0，挑出所有非0元素，放到数组首部，数组后部都设为0；
        //TC: O(n)
        //SC: O(1)
        int n = nums.size();
        int numZeroes = 0;
        //counting zeroes
        for(int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                numZeroes++;
            }
        }
        int indexNonZero = 0;
        for(int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[indexNonZero++] = nums[i];
            } 
        }
        for (int i = n-numZeroes; i < n; i++) {
            nums[i] = 0;
        }
    }
#endif

#if 0
    void moveZeroes(vector<int>& nums) {
        //方法二：双指针，包括遍历指针(枚举指针)，重新排列后的非零元素索引指针
        //TC: O(n)
        //SC: O(1)
        int indexNonZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[indexNonZero++] = nums[i];
            }
        }
        for (int i = indexNonZero; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
#endif

#if 1
    void moveZeroes(vector<int>& nums) {
        //方法三，类似方法2的双指针，但是把两个迭代过程合并，用swap而不是赋值，实现更高效的数据排列；
        //TC: O(n)
        //SC: O(1)
        for (int cur, lastNonZeroIndex = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[cur], nums[lastNonZeroIndex++]);
            }
        }
    }
#endif
};
// @lc code=end

