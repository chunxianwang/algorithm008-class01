/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
/*
用二维数组作为哈希列表，表示某数字在某一维度上是否出现过（行、列、3x3 box内）；

如row[i][9] == 1; 表示第i行，出现过9； col[j][5] == 0，表示第j列，没出现过5;

board索引 (index_row/3)*3 + index_col/3
*/
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};
        int col[9][10] = {0};
        int box[9][10] = {0};
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                int curNum = board[i][j] - '0';
                if(row[i][curNum]) return false;
                if(col[j][curNum]) return false;
                if(box[j/3 + (i/3)*3][curNum]) return false;
                
                row[i][curNum] = 1;
                col[j][curNum] = 1;
                box[j/3 +(i/3)*3][curNum] = 1;
            }
        }
        return true;
    }
};
// @lc code=end