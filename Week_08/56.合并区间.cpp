/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
/*
先对未合并区间按照左端点大小排序；
第一个未合并区间放入合并区间数组；
遍历剩余未合并区间，
如果待合并区间左端点大于已合并区间数组最后一个区间的右端点， 说明这是一个非连续区间，push到合并区间数组；
如果待合并区间左端点小于已合并区间数组的最后一个区间的右端点，则把此合并区间数组的最后一个区间更新为（原右端点和未合并区间右端点的最大值）
*/

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i=0; i<intervals.size(); i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) merged.push_back({L, R});
            else merged.back()[1] = max(merged.back()[1], R);
        }
        return merged;
    }
};
// @lc code=end

