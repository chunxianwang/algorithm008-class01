/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
/*
典型的DFS-backtrace题目
练习backtrace结构
时间复杂度：O(m*n*4*k)   m、n，二维表格行和列；4，四邻域；k，单词平均长度；
*/

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row =0; row<board.size(); row++) {
            for(int col=0; col<board[0].size(); col++) {
                if(backtrace(board, word, 0, row, col))
                    return true;
            }
        }
        return false;
    }
private:
/**
 * @brief 递归查找二维表格中row行、col列的四邻域内是否和单词的第characterIndex个字母匹配
 * 
 * @param board 二维表格
 * @param word  待查找单词
 * @param characterIndex 单词中字母索引
 * @param row 表格的行
 * @param col 表格的列
 * @return true 在表格中找到了单词中的字母
 * @return false 在表格中没找到单词中的字母
 */
    //注意！！！如果不用引用（别名），时间复杂度和空间复杂度都会变差，超时！
    bool backtrace(vector<vector<char>>& board, string& word, int characterIndex, int row, int col) {
        //backtrace step1， 递归终止条件
        if(board[row][col] != word[characterIndex])  //单词中字母和表格不相等，此路径走不通
            return false;
        if(word.size()-1 == characterIndex)  //最后一个字母也相等，返回匹配成功
            return true;
        //backtrace step2，处理当前层逻辑
        char tmp = board[row][col];
        board[row][col] = 0; //避免该位重复，把访问过的网格元素改成非字母字符
        characterIndex++;

        //backtrace step3，进入到下一层
        if ((row>0 && backtrace(board, word, characterIndex, row-1, col))  //四邻域路径，向左，上、右、下
        ||  (col>0 && backtrace(board, word, characterIndex, row, col-1))  
        ||  (row<board.size()-1 && backtrace(board,word, characterIndex, row+1, col))
        ||  (col<board[0].size()-1 && backtrace(board, word, characterIndex, row, col+1))) {
            return true;
        }
        //backtrace step4，，恢复当前层状态
        board[row][col] = tmp;
        return false;
    }
};
// @lc code=end

