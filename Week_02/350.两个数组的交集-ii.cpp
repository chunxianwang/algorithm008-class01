/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
        /*
        方法一：hash_map
        思路：属于比较两组数据内容关系的题目，可以用hash_map表示其中一组数据的元素分布情况，
        用另外一个数组逐元素查询hash_map，统计两者关系。
        步骤：
        1.如果nums1元素个数大于nums2，则交换数组元素；
        2.把nums1数组放入hash_map，value为相应元素（key）在数组中的个数；
        3.遍历nums2，检查是否在m中存在：
           如果存在，且计数（value）为正，则
               把元素拷贝到nums1[k]，且k++;
               m中相应元素的计数减1
        4.返回nums1的前k个元素

        时间复杂度O(m+n)
        空间复杂度0(min(n,m))，因为第一步取较小素组存入hash_map
        */
    #if 0
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);  //调换实参顺序的操作
        }
        unordered_map<int, int> m;
        for (auto n : nums1) {
            m[n]++;        //数组放入hash_map的操作
        }
        int k = 0;
        for (auto n : nums2) {
            auto it = m.find(n);
            if (it != end(m) && --it->second >= 0) {    //先减再比较大小，也可以写成: it->second-- > 0
                nums1[k++] = n;
            }
        }
        return vector(begin(nums1), begin(nums1) + k);
    }
    #endif

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> m;
        for (auto n : nums1) {
            m[n]++;
        }
        int k = 0;
        for (auto n : nums2) {
            auto it = m.find(n);
            if (it != end(m) && --it->second >=0) {
                nums1[k++] = n;
            }
        }
        return vector(begin(nums1), begin(nums1) + k);
    }








};
// @lc code=end

