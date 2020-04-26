/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
#if 0
//两遍哈希
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++)
            m[nums[i]] = i;         //向map中添加元素
        
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)     //如果m中存在对应的键值，并且不为i
                return {i , m[target-nums[i]]};
        }
        return {};
    }
#endif
#if 1
//一遍哈希
vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i]) != m.end())      //m中存在对应的键值
                return {m[target-nums[i]] , i};        //m[target-nums[i]]为已经加入map的元素的索引，所以小于本轮循环中的i，放在前面

            m[nums[i]]=i;       //向map中添加元素
        }
        return {};
    }
#endif




};
// @lc code=end

