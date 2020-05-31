/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
/*
自底向上，动态规划：
当前位置路径，为下一层相邻两个元素路径较小者+当前位置路径的大小
*/

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> line(triangle[n-1]);
        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<= i; j++){
                line[j] = triangle[i][j] + min(line[j], line[j+1]); 
            }
        }
        return line[0];
    }
};
// @lc code=end

