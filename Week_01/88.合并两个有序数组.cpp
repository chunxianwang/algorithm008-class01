/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 * 
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出: [1,2,2,3,5,6]
 * 
 * 题解：
1.充分利用原数组的有序性
2.数组尾部有“写”空间，避免写头部会引起数据覆盖，因此采用数组倒序操作
3.注意考虑考虑m = 0的特殊情况
4.注意访问数组元素的溢出！！！
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

