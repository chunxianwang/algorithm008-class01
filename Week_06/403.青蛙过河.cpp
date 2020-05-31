/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */
//参考题解：https://leetcode-cn.com/problems/frog-jump/solution/cji-yi-hua-sou-suo-kuai-yu-96yi-shang-de-yong-hu-b/
// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> h; //存放所有石头的位置
        for(auto x:stones) h.insert(x);
        unordered_map<long long, bool> memo;
        function<bool(int, int)> dfs = [&] (int x, int y) {
            if(y<=0 || !h.count(x)) return false;
            if(x==1 && y==1) return true;

            long long t = (long long)x<<32|y;
            if(memo.count(t)) return memo[t];

            if(dfs(x-y,y) || dfs(x-y, y-1) || dfs(x-y, y+1))
                return memo[t] = true;
            return memo[t] = false;
        };

        for (int i=1; i<=1001; i++)
            if (dfs(stones.back(), i))
                return true;
        return false;
    }
};
// @lc code=end

