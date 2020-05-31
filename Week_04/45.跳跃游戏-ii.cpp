/* 5.25
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
//正向: 遍历数组，维护当前位置最远可达边界maxPos; 
//     维护‘当前步’的最远可达位置，如果到达，则步数+1，且更新‘当前步’的最远可达位置；
//     注意：题目中有能到达最远位置的前提条件，在遍历数组时，我们不访问最后一个元素， 即i<nums.size()-1；
//          这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，否则就无法跳到最后一个位置了。
//          如果访问最后一个元素，在边界正好为最后一个位置的情况下，我们会增加一次「不必要的跳跃次数」，
//          因此我们不必访问最后一个元素。
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, steps = 0, end = 0;;
        for (int i=0; i<nums.size()-1; i++) {
            if (maxPos >= i) {
                maxPos = max(reach, i + nums[i]);
                if (i == end) {
                    steps++;
                    end = maxPos;
                }
            }
        }
        return steps;
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

