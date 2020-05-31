/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */


/**
 * @file 51.n皇后.cpp
 * @author your name (you@domain.com)
 * @brief 思路：回溯思路，一行只能放入一个皇后，因此回溯每一行，从当前行进入到下一行；
 * 在当前行，对每一个列元素尝试放入皇后，并判断是否和棋盘上已放入的行有冲突，无冲突，把当前行存入棋盘，并进入下一行；
 * 如果棋盘所有行都被摆满，则说明已经得到一个结果；存入结果数组；回退，寻找是否有其它满足要求的棋局。
 * 
 * @version 0.1
 * @date 2020-05-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
    vector<vector<string>> res;  //存结果
    vector<string> board;  //存棋盘

public:
    vector<vector<string>> solveNQueens(int n) {
        string line(n, '.');   //存每一行
        solveNQueens(line, 0, n);  //从第0行开始
        return res;
    }
private:
    void solveNQueens(string& line, int row, int n) {
        if (board.size() == n) {  //如果棋盘存够了n行，就不用再继续试下一行了
            res.push_back(board);
            return;
        }
        for (int i=0; i<n; ++i) {  //在当前行，遍历每一列的元素，如果可以放如皇后，那就
            if (checkAll(row, i, n)) {
                line[i] = 'Q';
                board.push_back(line);
                line[i] = '.';  //恢复为默认无皇后的空行，用于存下一行结果
                solveNQueens(line, row+1, n);
                board.pop_back(); //回溯处理返回的问题，如果return，那就把棋盘的上一行删掉；
            }
        }
    }
    bool checkAll(int row, int col, int n) {  //判断当前[row, col]位置是否适合放皇后？
        for(int i=1; i<=row; ++i) {
            if(col-i>=0 && board[row-i][col-i]=='Q') //左上
                return false;
            if(col+i<n && board[row-i][col+i]=='Q') //右上
                return false;
            if(board[row-i][col]=='Q') //上方
                return false;
        }
        return true;
    }
};
// @lc code=end

