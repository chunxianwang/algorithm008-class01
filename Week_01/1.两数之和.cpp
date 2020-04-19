/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        #if 0
        //方法1，暴力搜索
        //TC:O(n^2)
        //SC:O(1)
        int i,j;
        for (i=0; i<nums.size()-1; i++) {
            for (j=i+1; j<nums.size(); j++) {
                if (nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {i,j};
        #endif

        #if 1
        //方法2，两遍哈希
        //TC:O(n^2)
        //SC:O(1)
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++)
            m[nums[i]] = i;         //向map中添加元素
        for(int i=0;i<nums.size();i++) {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i) 
            //如果m中存在对应的键值，并且不为i自身，适用于target/2元素在数组中出现的情况
                return {i , m[target-nums[i]]};
        }
        return {};
        #endif  
    };
};
// @lc code=end

