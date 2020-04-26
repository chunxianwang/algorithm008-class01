/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 * 4.20 每日一题
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        #if 0
        /*方法一：hash_map  --8ms
        解题思路：
        情况一：数字相同位置相同，比较容易统计，两string中逐个元素对比就行
        情况二：数字相同位置不同，可用map查询来实现
        步骤：
        1.比较string，统计数字相同位置相同的数量，同时把secret存入map；
        2.map查询，统计guess字符在map中出现次数；
        3.剔除情况一在步骤2中统计的次数；

        步骤2具体操作：
        把sectret存入map，每个元素的value置1；
        guess字符在map中查询，查到就返回1，查不到则返回0；
        TC:O(n)
        SC:O(n)
        */
        int acnt = 0;
        int bcnt = 0;
        unordered_map<char, int> um;
        for (int i = 0; i < secret.size(); i++) {
            um[secret[i]]++;         //string每个元素作为key存入map，value均设为1
            acnt += (secret[i] == guess[i]);
        }
        for (auto& c : guess) {
            bcnt += (um[c]-- > 0);  //字符能否在map中查到，能查到则
        }
        bcnt -= acnt;               //注意减去数字相同且位置相同的情况
        return to_string(acnt) + "A" + to_string(bcnt) + "B";
        #endif


        #if 1
        /*方法二：数组，bucket  --4ms
        思路：两个长度为10的数组作为两组bucket，对应0～9
        除了数字相同且位置相同字符之外（计入An），其它字符放入bucket内进行计数
        累加两组bucket的较小计数值，得到Bn
        时间复杂度：O(n)
        空间复杂度：O(1)

        */
        int aCnt = 0;
        int bCnt = 0;
        vector<int> sVec(10, 0); // 0 ~ 9 for secret
        vector<int> gVec(10, 0); // 0 ~ 9 for guess 
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt; 
            } else {
                ++sVec[c1-'0'];
                ++gVec[c2-'0'];
            }
        }
        // count b 
        for (int i = 0; i < sVec.size(); ++i) {
            bCnt += min(sVec[i], gVec[i]);
        }
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
        #endif
    }
};
// @lc code=end

