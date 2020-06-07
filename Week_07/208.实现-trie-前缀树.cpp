/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

