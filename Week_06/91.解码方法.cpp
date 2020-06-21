/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法-动态规划
 */
// @lc code=start
#if 0
/**
 * 内核为非波拉契数列的动态规划问题，特点是需要考虑的情况比较多
 * 
 * s[i] 为字符串s的第i个字符，f(i)表示到s[i]一共有多数种解码方式
 * 
 * if(s[i]=='0') 
 *     if (s[i-1]=='1' || s[i-1]=='2') -->f(i)=f(i-2)
 *        //就是说，最后两位只能合并解码为10 或20， 例如1212120，
 *        //解码的数量和12121相同（最后两位20是唯一解，解码总数不增加。）；
 *     else -->return 0;
 *        //字符串非法，，就是说0只能出现在1或2的后面，组成10或20，如果是30、40...，那就不能正常解码了
 * if(s[i]!='0')
 *      if(s[i-1]==1 || (s[i-1]&&1<=s[i]<=6)) -->f(i) = f(i-1) + f(i-2)
 *         //就是最后两位在11-26之间，如1212121，可以翻译为12121+21或121212+1
 *      else --> f(i) = f(i-1);
 *         //就是最后两位不再11到26之间，如1212132，只能翻译成121213+2
 */ 


class Solution {
public:
    int numDecodings(string s) {
        if (s[0]=='0') return 0;
        int prepre = 1;  //f(i-2)
        int cur = 1;  //f(i)
        for (int i=1; i<s.size(); i++) {
            int pre=cur;   //更新f(i-1)
            if(s[i] == '0') {
                if(s[i-1]=='1' || s[i-1]=='2') cur = prepre; //f(i) = f(i-2)
                else return 0;
            } else {
                if (s[i-1]=='1' || (s[i-1]=='2' && s[i]>='1' && s[i]<='6'))
                    cur = pre +prepre; //f(i) = f(i-1) + f(i-2)
                else
                    cur = pre;  //f(i) = f(i-1)
            }
            prepre = pre; //更新f(i-2)
        }
        return cur;
    }
};
#endif
#if 1
//标准动态规划写法，避免奇技淫巧的陌生感
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 1); // 存储的是 dp[i + 1] 是 s[i] 的解码数量， 之所以是 cache[i + 1] ， 是为了防止开始循环时 f(i-2) 出现访问越界
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2')
                    dp[i + 1] = dp[i - 1];
                else
                    return 0; // 非法字符串， 无解
            }else{
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) // 也就是到 i 位置的最后两位数字为为 [10, 26] 可以和并转换为一个字母
                    dp[i + 1] = dp[i - 1] + dp[i];
                else
                    dp[i + 1] = dp[i];
            }
        }
        return dp[s.size()];
    }
};
#endif


// @lc code=end

