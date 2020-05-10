/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 * 已参考中外题解
 * 思路：两数据集合关系的问题，最直接可以想到，可用hash_table来实现；--方法一
 * 另外，也可用数组模拟哈希表来实现；--方法二
 * 
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    #if 0
    //方法一：hash table，迭代器操作
    //1.枚举s，列入哈希表，value是字符出现次数；
    //2.枚举t，如果能在哈希表中找到，则表中value减1，如果某字符在表中找不到，或即使找到了，出现次数和s中不一致，则false
    //缺点：没有显性地比较两字符串中字符的数量，优化如下“方法一优化版”
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> um;
        for(auto n : s) {
            um[n]++;
        }
        for(auto n : t) {
            auto it = um.find(n);
            if (it == um.end() || --it->second < 0)
            return false;
            //以上三行的这种写法，执行时间往往是<=20ms，打败45%及以上
            /*
            另外一种低效写法，执行时间一般>=30ms，仅仅打败35%及以下
            //auto it = um.find(n); //不使用迭代器
            if (um.find(n) == um.end() || --um[n] <0)
            return false
            //分析原因，实质上是多做了一次hash_map查询
            */
        }
        return true; 
    }
    #endif

    #if 0
    //方法一优化版：hash table，
    //1.枚举两个string中的字符，加减操作哈希表value
    //2.枚举哈希表，如果有不等于0的元素，返回false，否则返回true
    //这样，后半部分代码更好理解。
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char, int> um;
        for (int i = 0; i < n; i++) {
            um[s[i]]++;
            um[t[i]]--;
        }
        for (auto n :um) 
            if (n.second) return false;
        return true;
    }
    #endif
    #if 1
    //方法二：用长度为26的数组代替哈希表
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        int counts[26] = {0};
        //vector<int> count(26,0);
        for (int i = 0; i < n; i++) {
            counts[s[i] - 'a']++;  //字符转数字
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
             if(counts[i]) return false;
        }
        return true;
    }
    #endif
};
// @lc code=end

