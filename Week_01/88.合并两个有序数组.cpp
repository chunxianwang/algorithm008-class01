/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        #if 0
        //错误！！！没有考虑m = 0 的情况，导致数组访问溢出
        //方法一：三指针，从后往前找大数，放入数数组后部
        //nums2原始指针，作为迭代指针，指向nums2尾部，从后往前迭代，到数组首结束
        //结果数组指针，从后往前移动；
        //num1原始指针，从后往前移动；
        int tar_ptr = m + n - 1;
        int num1_ptr = m - 1;
        n--;
        while (n >= 0) {
            if (nums2[n] >= nums1[num1_ptr]) {
                nums1[tar_ptr] = nums2[n];
                n--;
            } else {
                nums1[tar_ptr] = nums1[num1_ptr];
                num1_ptr--;
            }
            tar_ptr--;
        }
        #endif


        #if 1
        //方法一：三指针，从后往前找大数，放入数数组后部
        //nums2原始指针，作为迭代指针，指向nums2尾部，从后往前迭代，到数组首结束
        //结果数组指针，从后往前移动；
        //num1原始指针，从后往前移动；
        //debug, 考虑了m = 0的情况
        int tar_ptr = m + n - 1;
        while (n > 0) {
            if (m > 0 && nums1[m-1] > nums2[n - 1]) {  //排除m = 0时导致的异常
                nums1[tar_ptr] = nums1[m - 1];
                m--;
            } else {
                nums1[tar_ptr] = nums2[n - 1];
                n--;
            }
            tar_ptr--;
        }
        #endif
    }
};
// @lc code=end

