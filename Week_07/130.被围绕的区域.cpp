/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
// @lc code=start
//题目等价于：和边界'O'连通的'O‘保留，其余所有元素都置为’X‘
//dfs方法，先从边界开始，进行dfs搜索'O‘，把搜索到的所有’O‘置为特殊符号’1‘
//遍历所有元素，遇到’1‘，置为‘O',其它均置为‘x‘
class Solution {
public:
    void solve(vector<vector<char>>& board) {
       if (board.size() == 0) 
           return ;
        int row = board.size(), col = board[0].size();
        for (int i=0; i<row; i++) {
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }
        for (int j=0; j<col; j++) {
            dfs(board, 0, j);
            dfs(board, row-1, j);
        }
        for (int i=0; i< row; i++) {
            for (int j=0; j<col; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row>=0 && col >=0 && row<board.size() && col<board[0].size() && board[row][col]=='O') {
            board[row][col] = '1';
            dfs(board, row-1, col);
            dfs(board, row, col-1);
            dfs(board, row+1, col);
            dfs(board, row, col+1);
        }
    }
};
// @lc code=end