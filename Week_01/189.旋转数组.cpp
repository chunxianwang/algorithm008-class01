/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        #if 0
        //三次反转：整体反转，前k部分反转，后length-k部分反转
        //也可以先反转后面的k项目，再反转前面length-k项，最后整体反转，效果一样。
        //tc:O(n)
        //sc:O(1)
        k = k % nums.size();
        for (int i = 0; i < nums.size()/2; i++) {
            swap(nums[i], nums[nums.size() - i - 1]);
        }
        for (int i = 0; i < k/2; i++) {
            swap(nums[i], nums[k - i -1]);
        }
        for (int i = 0; i < (nums.size() - k)/2; i++) {
            swap(nums[k + i], nums[nums.size() - 1 - i ]);
        }
        #endif

        #if 1
        //三次反转的另外一种coding方式，在类内定义一个reverse()成员函数
        //数组旋转函数中，三次调用reverse()
        int l = nums.size();
        k = k % l;
        reverse(nums, 0, l-1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, l-1);
        #endif

        #if 0
        //一步步移动，结果是“超出时间限制”
        //tc:O(kn)，k如果很大时，会超时
        //sc:O(1)
        int l = nums.size();
        k = k % l;
        for (int i = k; i > 0; i--) {
            int temp = nums[l - 1];
            for (int j = l -1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
        }
        #endif
    }
};
// @lc code=end

