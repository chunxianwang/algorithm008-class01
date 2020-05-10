/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    #if 0
    //暴力法：用x做n-1次累乘，时间复杂度O(n)，超过时间限制
    //tc:O(n)
    //sc:O(1)
    double myPow(double x, int n) {
        long long N = n < 0 ? -n : n; //int 表达范围-2^32 ~ 2^32-1， 最小值取绝对值后超过int表达范围，因此要用64位的long long数据类型
        x = n < 0 ? 1/x : x;
        double ans = 1;
        for (long long i = 0; i < N; i++) //注意用64位的long long数据类型
            ans = ans * x;
        return ans;
    }
    #endif

    #if 0
    //快速幂算法（递归）
    //定义fastPow的递归函数
    //tc:O(logn)
    //sc:O(1)
    double fastPow(double x, long long n) {
        if (n == 0) {    //递归终止条件
            return 1.0;
        }
        double half = fastPow(x, n / 2);  //处理当前层逻辑 && 下探到下一层
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        x = n < 0 ? 1/x : x;
        N = n < 0 ? -N : N;
        return fastPow(x, N);
    }
    #endif

    #if 1
    //快速幂运算（循环）
    double myPow(double x, int n) {
        long long N = n;
        x = n < 0 ? 1/x : x;
        N = n < 0 ? -N : N;
        double ans = 1;
        double current_product = x;
        for (long long i = N; i ; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
    #endif
};
// @lc code=end

