/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
//有了这个Trie，看怎么利用，实现解题
class Trie {
private:
    bool isEnd;
    Trie* next[26] = {nullptr};                        //数组指针，表示26个指针元素组成的一维数组
public:
    /** Initialize your data structure here. */
    Trie() {                              //构造结点：1，初始化结束符isEnd，未结束；2，为新结点分配内存；
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    /** Inserts a word into the trie. */
    //从word的起始字符开始和trie中的next链接进行比对；
    //链接存在。沿着链接移动到树的下一个子层。算法继续搜索下一个键字符。
    //链接不存在。创建一个新的节点，并将它与父节点的链接相连，该链接与当前的键字符相匹
    void insert(string word) {
        Trie* node = this;            //指向当前结点
        for (char c : word) {
            if (node->next[c-'a'] == NULL) {   //如果指向空，那就构造一个新结点；
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a']; //指向下一个结点
        }
        node->isEnd = true;           //标记单词结束
    }
    
    /** Returns if the word is in the trie. */
    //在trie中，且是trie中的一个完整单词，而不仅是一个前缀；
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c-'a'];
            if (node == NULL) {
                return false;
            }
        }
        return node->isEnd;  //返回是否单词结束
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c-'a'];
            if (node == NULL) {
                return false;   //返回没有找到完整的前缀
            }
        }
        return true;    //返回找到了完整的前缀
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //先把words，写到trie中
        Trie trie;
        for (auto& w : words) {
            trie.insert(w);
        }
        vector<string> res;
        
        
        for (int row=0; row<board.size(); row++) {
            for (int col; col<board[0].size(); col++) {
                string line;
                backtrace(board, res, trie, line, row, col);
            }
        }
        return res;
    }
private:
    void backtrace(vector<vector<char>>& board, vector<string>& res, Trie& trie, string line, int row, int col) {
        if (trie.search(line)) {
            res.push_back(line);
            return;
        } else if (!trie.startsWith(line)) {
            return; 
        }
        char tmp = board[row][col];
        board[row][col] = 0;
        if(row>0) {
            backtrace(board, res, trie, line+(board[row-1][col]), row-1, col);
        }
        if (col>0) {
            backtrace(board, res, trie, line+(board[row][col-1]), row, col-1);
        }
        if (row<board.size()-1) {
            backtrace(board, res, trie, line+(board[row+1][col]), row+1, col);
        }
        if (col<board[0].size()-1) {
            backtrace(board, res, trie, line+(board[row][col+1]), row, col+1);
        }
        board[row][col] = tmp;
    }

};
// @lc code=end

