/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
/*
遇到有序数组，就要从分利用其有序性
往往课采用倒序和双指针左右包抄的数组访问方式，
有时能在降低时间、空间复杂度上，带来很好的效果。
*/

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {

        //读题写思路
        //1.负数取绝对值，再排序，再平方
        //2.平方，再对数组进行排序
        //3.双指针，前后包抄

        /*双指针方法，自由发挥写出的ugly代码，待批判！！！
        int l = A.size();   //变量含义不够明晰
        vector<int> res(l);
        int left = 0, right = l-1;
        while (left <= right) {     退出条件不够明晰，如果写成了left < right还会遇到奇数元素数组，中间元素可能没法访问的错误。
            if (A[left]*A[left] > A[right]*A[right]) {
                res[l-1] = A[left]*A[left];   //i-1会带来额外的n次计算
                left++;
            } else {
                res[l-1] = A[right]*A[right];
                right--;
            }
            l--;
        }
        return res;
        */
        //双指针方法，同样的思路，但是代码更优美、高效
        int len = A.size();
        vector<int> res(len);   //变量的含义更清晰
        int left = 0, right = len - 1, i = right;
        while (i >= 0) {        //更清晰的迭代器
            if (A[left]*A[left] > A[right]*A[right]) {
                res[i] = A[left]*A[left];
                left++;
            } else {
                res[i] = A[right]*A[right];
                right--;
            }
            i--;
        }
        return res;
    }
};
// @lc code=end

