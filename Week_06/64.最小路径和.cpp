/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
/**
方法一
暴力解法：使用递归，对每个元素，考虑两条途径，向右“和”向下走，在这两条路径中挑选路径权值和较小的一个
时间复杂度：0(2^(m+n))，每次移动可以有两种选择；
空间复杂度：0(m+n)，递归的深度是m+n；

方法二
二维动态规划
问题分解后，描述为：每个位置，其移动路径的最小值是：自身位置所表示的路径值+（走到右方和下方位置所用路径的较小路径）
这里进行动态规划问题分解时，有一个假设，就是如果求走到当前位置的路径值，那么走到当前位置的右方、和下方位置的路径值已知。
时间复杂度：O(m * n)；
空间复杂度：O(m * n),用新的二维数组保存各个位置的路径值； 或O(1)，不用新数组，直接在原数组上修改；
*/

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
#if 1
//方法二：二维动态规划
        int rows =grid.size();
        if (rows==0) return 0;
        int columns =grid[0].size();
        if (columns==0) return 0;
        for (int i=1; i<columns; i++) {     //最下方的一行
            grid[0][i] += grid[0][i-1];
        }
        for (int j=1; j<rows; j++) {     //最右方的一列
            grid[j][0] += grid[j-1][0];
        }
        for (int i=1; i<rows; i++) {
            for (int j=1; j<columns; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[rows-1][columns-1];
#endif
    }
};
// @lc code=end

