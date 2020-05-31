/* 5.25
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
/**
 * 三数之和的升级版，多一个for循环，注意处理重复数字
 * 处理重复时，避免[0,0,0,0]被过滤掉
 * 
 **/

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int size_ = nums.size();
        for (int a = 0; a < size_-3; a++) {
            if (a>0 && nums[a]==nums[a-1]) continue; //处理重复数字
            for (int b=a+1; b<size_-2; b++) {
                if (b>a+1 && nums[b]==nums[b-1]) continue;//处理重复数字
                int c = b+1, d = size_-1;
                while(c < d){
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum > target) d--;
                    else if (sum < target) c++;
                    else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c<d && nums[c]==nums[++c]) continue;//处理重复数字
                        while (c<d && nums[d]==nums[--d]) continue;//处理重复数字
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

