/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
/*
双向BFS
思路：
分别从beginword 和 endword两端开始，用BFS维护两个树的生长；
生长原则如下：
  如果待长出的分支，属于wordList，那就让这个分支长出来；
  如果不属于，则不让这个分支长出来；

如果两个树在某一层有相同的枝桠，则说明可以从beginword 通过接龙得到 endword

具体实现：
用BFS方式逐层维护树的生长，某层树结构用集合（set）来表示；
为了降低搜索的空间和时间复杂度，每次都在两个树中，选当前层尺寸较小的树进行BFS；

*/

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;
        //定义两个方向的树（仅需保存当前BFS的层中的数据）
        unordered_set<string> from({ beginWord });  
        unordered_set<string> to({ endWord });

        int ans = 2;
        while (!from.empty())    
        {
            unordered_set<string> next;
         for (auto& word : from)
            {
                wordSet.erase(word);
            }
            for (auto& word : from)
            {
                for (int i = 0; i < word.size(); i++)
                {
                    string s = word;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        s[i] = c;
                        if (wordSet.count(s) == 0) continue;
                        next.insert(s);
                        if (to.count(s) == 0) continue;
                        return ans;
                    }
                }
            }
            from = next;
            if (from.size() > to.size())
            {
                swap(from, to);//在较小尺寸的树上进行下一次BFS，降低空间、时间复杂度
            }
            ans++;
        }
	return 0;
    }
};
// @lc code=end

