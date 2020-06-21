/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#if 0
//纵向扫描
//扫面每一个字符串的第1、2、3、4...个字符
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        int len = strs[0].size();
        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
#endif

#if 1
//横向遍历：先假设公共前缀为第一字符串，遍历后面的每个字符串，
//每遍历一个字符串中的字符，更新一下公共前缀（不断缩短），结束遍历所有的字符串后，得到结果。
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) break;
        }
        return prefix;
    }
    
    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min (str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) index++;
        return str1.substr(0, index);
    }
};

#endif

// @lc code=end

