/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
private:
    vector<int> tmp;
    int mergeSort(vector<int>& nums, int l, int r) {
        //退出当前层逻辑
        if (l >= r) return 0;
        //进入下一层
        int mid = (l+r) >> 1;
        int cnt = mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r);
        //处理当前层逻辑：找反转对
        int j=mid+1;
        //如果nums[i] 产生了j对， 那么nums[i+1]产生了j+对；
        for (int i = l; i <= mid; i++) {
            while (j <= r && (double)nums[i] > 2*(double)nums[j])
                j++;
            cnt += j - (mid + 1);
        }
        //处理当前层逻辑：合并两个子序列
        int i=l, k = 0;
        j=mid+1;
        while (i <= mid && j <= r) tmp[k++] = (nums[i]< nums[j]) ? nums[i++] : nums[j++];
        while (i <= mid) tmp[k++] = nums[i++];  
        while (j <= r) tmp[k++] = nums[j++];   
        for(int i=0; i<r-l+1; i++) nums[i+l] = tmp[i];
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        tmp.resize(nums.size(), 0);
        int cnt = 0;
        cnt = mergeSort(nums, 0, nums.size()-1);
        return cnt;
    }
};
// @lc code=end

