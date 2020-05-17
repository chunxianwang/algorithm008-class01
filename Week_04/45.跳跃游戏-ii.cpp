/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
//和题目55相比，新增了最短路径要求，可以用贪心实现。
//和题目55类似，有两种方法：
//1.正向跳跃，
//2.反向跳跃

// @lc code=start
#if 0
//正向
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
#endif
#if 1
//反向
class Solution {
public:
    //反向查找，贪心算法
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        if(count(nums.begin(),nums.end(),1)==nums.size())
            return nums.size()-1;
        int pos = nums.size()-1; //标记每次的落脚位置，因为是反向找，所以最开始在最后一个元素的位置
        int steps = 0;
        while(pos > 0)
        {
            //从左向右找可以到达下一步落脚点的最远位置，保证他的最小步数。
            for(int i = 0;i < pos;++i)
            {
                //如果从该位置(i)可以到达(+nums[i])下一步的落脚点(pos),就将该位置作为新的落脚点向前移动。
                if(i+nums[i]>=pos)
                {
                    pos = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};
#endif


// @lc code=end

