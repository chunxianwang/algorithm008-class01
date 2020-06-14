/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
// @lc code=start
class Solution {
private:
    //行，列，小格内某数字是否已填标记
    bool visitRow[9][9] = { false };
    bool visitCol[9][9] = { false };
    bool visitBox[9][9] = { false };
public:
    void solveSudoku(vector<vector<char>>& board) {
        //先记录表格中的初始状态
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    visitRow[i][ board[i][j] - '1'] = true;
                    visitCol[j][ board[i][j] - '1'] = true;
                    visitBox[ (i / 3) * 3 + j / 3 ][ board[i][j] - '1'] = true;
                }
            }
        }
        backTrace(board, 0, 0);
    }
private:
/**
 * @brief 递归函数
 *        注意其中的return逻辑
 * @param board 
 * @param row 
 * @param col 
 * @return true 
 * @return false 
 */
    bool backTrace(vector<vector<char>>& board, int row, int col) {
//递归step1:递归终止条件
        if (row > 8) return true;
        //如果当前位置空，即没填入数字
        if (board[row][col] == '.') {
//递归step2:处理当前层逻辑        
            for (int i=0; i<9; i++) {
                int boxIndex = (row/3)*3 + col/3;
                if (visitRow[row][i] || visitCol[col][i] || visitBox[boxIndex][i]) continue;
                board[row][col] = i + '1';
                visitRow[row][i] = true;
                visitCol[col][i] = true;
                visitBox[boxIndex][i] = true;
//递归step3:进入到下一层
                if (backTrace(board, row+(col+1)/9, (col+1)%9)) return true; //如果写成return(backTrace)形式，不能执行下面的恢复当前层状态语句

//递归step4:恢复当前层状态
                board[row][col] = '.';
                visitRow[row][i] = false;
                visitCol[col][i] = false;
                visitBox[boxIndex][i] = false;
            }
            return false;
        }
//递归step3:进入到下一层
        else return backTrace(board, row+(col+1)/9, (col+1)%9);
    }

};
// @lc code=end

