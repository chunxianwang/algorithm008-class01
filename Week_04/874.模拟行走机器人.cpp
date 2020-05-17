/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */
/*
机器人行走的每条规则都比较简单，但是规则条目较多；
重在考察从规则描述重抽象编程语言的基本功；

思路：
1.定义机器人四种基本行走步法，相对当前点，机器人向前、右、后、左走一步；
2.维护机器人运动方向状态，与基本步法相对应，用于指导机器人接下来怎么走；
3.执行运动命令：
3.1如果是转向命令，则改变上述运动方向状态，
3.2如果是行走命令，沿着当前方向一步步行走，判断机器人每个下一步位置是否与障碍物冲突：
   若冲突，不往下一步走了，结束本次运动命令；
   若不冲突，更新机器人位置到下一步；
4.每走一步，判断是否离远点更远，最后找到最远距离
*/

// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
#if 0
//set维护障碍物集合，查询效率较低
        int ans = 0;
        set<vector<int>> ob;
        for (auto& p : obstacles) ob.insert(p);
        vector<vector<int>> dd = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int dir = 0;
        vector<int> current_pos = {0, 0};
        for (auto& c : commands) {
            dir = (c == -2) ? (dir+4-1)%4 : dir;
            dir = (c == -1) ? (dir+1)%4 : dir;
            for(int i=0; i<c; i++) {
                vector<int> next_pos = {current_pos[0] + dd[dir][0], current_pos[1]+dd[dir][1]};
                if(ob.count(next_pos) !=0 ) break;
                current_pos = next_pos;
                ans = max(ans, current_pos[0]*current_pos[0]+current_pos[1]*current_pos[1]);
            }
        }
        return ans;
#endif
#if 1
//map+set,性能稍有提升
        int ans = 0;
        unordered_map<int, unordered_set<int>> ob;
        for (auto& p : obstacles)
        {
            ob[p[0]].insert(p[1]);
        }

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int dir = 0;
        vector<int> pos = { 0,0 };

        for (auto& c : commands)
        {
            dir = (c == -2) ? (dir + 4 - 1) % 4 : dir;
            dir = (c == -1) ? (dir + 1) % 4 : dir;
            for (int i = 0; i < c; i++)
            {
                vector<int> next = { pos[0] + dd[dir][0], pos[1] + dd[dir][1] };
                if (ob[next[0]].count(next[1]) != 0) break;
                pos = next;
                ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
            }
        }
        return ans;
#endif
    }

};
// @lc code=end

