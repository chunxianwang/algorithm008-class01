/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(end) == bankSet.end()) return -1;
        unordered_set<string> from({start});
        unordered_set<string> to({end});
        
        int ans = 1;
        while (!from.empty()) {
            unordered_set<string> next;
            for(auto& word : from) {   
                bankSet.erase(word);   //如果不删除已访问过的元素，会超时
            }
            for (auto& word : from) {
                for(int i=0; i<word.size(); i++) {
                    string s = word;
                    for (auto& base : "ACGT") {
                        s[i] = base;
                        if (bankSet.find(s) == bankSet.end()) continue;
                        next.insert(s);
                        if (to.find(s) == to.end()) continue;
                        return ans;
                    }
                }
            }
            from = next;
            if (from.size()>to.size()) {
                swap(from, to);
            }
            ans++;
        }
        return -1; 
    }
};
// @lc code=end

