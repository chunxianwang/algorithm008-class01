/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
#if 1
/*
方法一：字符串排序法
1.先对每个字符串进行排序，得到排序字符串
2.枚举每个排序字符串，如果和其它排序字符串相等，则将原字符串其成组，放入结果中；
3.注意设置flag数组，标记字符串是否已放入结果中，
  如果已放入，则跳过。
时间复杂度：1000ms,0(NKlogK)  N 是strs长度，K是strs中字符串最大长度；
枚举每个字符串排序时，外部循环复杂度O(N),字符串内部排序时间为O(KlogK)
空间复杂度：O(NK),对应ans结果的空间尺寸
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> tmp = strs;
        for (int i = 0; i < tmp.size(); i++) {
            sort(tmp[i].begin(), tmp[i].end());
        }
        vector<int> vis = vector(strs.size(), 0);
        for (int i = 0; i < tmp.size(); i++) {
            vector<string> cur;
            if(vis[i] == 1) continue;
            vis[i] = 1;
            cur.emplace_back(strs[i]);
            for (int j = i+1; j < tmp.size(); j++) {
                if (tmp[i] == tmp[j]) {
                    cur.emplace_back(strs[j]);
                    vis[j] = 1;
                }
            }
            ans.emplace_back(cur);
        }
        return ans;
    }
#endif
#if 0
/*
方法二：两层哈希表
第一层：每个字符串中的字符作为key，字符出现次数作为value，形成字符串哈希表；
第二层：字符串组中的字符哈希表作为key，字符串作为value，形成字符组哈希表；
时间复杂度：200ms,0(NK)  N 是strs长度，K是strs中字符串最大长度；
空间复杂度：O(NK),对应ans结果的空间尺寸
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char,int>, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++) {
            map<char, int> tmp;
            for (auto n : strs[i]) {
                tmp[n]++;
            }
            hash[tmp].emplace_back(strs[i]);
        }
        for (map<map<char,int>, vector<string>>::iterator it = hash.begin(); it != hash.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
#endif
#if 0
/*
方法三：前两个方法结合到一起，字符串排序+单层哈希表  
关于emplace_back和push_back:
emplace_back能就地通过参数构造对象，不需要拷贝或者移动内存，
相比push_back能更好地避免内存的拷贝与移动，使容器插入元素的性能得到进一步提升。
在大多数情况下应该优先使用emplace_back来代替push_back。
时间复杂度：100ms,0(NKlogK)  N 是strs长度，K是strs中字符串最大长度；
枚举每个字符串排序时，外部循环复杂度O(N),字符串内部排序时间为O(KlogK)
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> m;
        for (auto n : strs) {
            string tt = n;
            sort(n.begin(), n.end());
            m[n].emplace_back(tt);
        }
        for (auto n : m) {
            ans.emplace_back(n.second);
        }
        return ans;
    }
#endif
};
// @lc code=end

