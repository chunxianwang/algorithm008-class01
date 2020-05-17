/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
/*
思路，
1.孩子胃口、饼干大小从小到大先排序；
2.从小胃口到大胃口遍历每个孩子，若当前派发饼干小于其胃口，那就派发下一个饼干；
直到其被满足，被满足孩子数+1；
接着派发下一个孩子，直到所有孩子被遍历或饼干没有了；
*/

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int num = 0;
        for(int i=0; i<g.size(); i++){
            for(; j < s.size(); j++) {
                if(g[i] <= s[j]) {
                    j++;
                    num++;
                    break;
                }
            }
        }
        return num;
    }
};
// @lc code=end

