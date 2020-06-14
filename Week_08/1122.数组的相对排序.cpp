/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */
//桶方法，先用一个0～1000的桶，统计arr1中元素分布情况。
//再根据arr2，在桶中取出相应内容。
// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v1(1001, 0);
        int n1 = arr1.size();
        int n2 = arr2.size();
        for (int i=0; i<n1; i++) {
            v1[arr1[i]]++;
        }
        int tmp = 0;
        for (int i=0; i<n2; i++) {
            while(v1[arr2[i]]>0) {
                arr1[tmp] = arr2[i];
                v1[arr2[i]]--;
                tmp++;
            }
        }
        for (int i=0; i<1001; i++) {
            while(v1[i]>0) {
                arr1[tmp] = i;
                v1[i]--;
                tmp++;
            }
        }
        return arr1;
    }
};
// @lc code=end

