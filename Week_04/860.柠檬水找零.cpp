/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
/*
维护一个现存5元、10元的数量（可用map或其它实现）
收到10块，找5块，现存5块数量减1；
收到20，有限找10+5，如果没有10块，就找5+5+5；维护相应现存零钱数量；

注意：同样思路，两种代码方式，代码量差别巨大！！！
*/
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
#if 0        
        if (bills.empty()) return true;
        unordered_map<int, int> mp;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) mp[5]++;
            else if (bills[i] == 10) {
                mp[5]--;
                mp[10]++;
                //if (mp[5] < 0) return false;
            }
            else if (bills[i] == 20) {
                int tmp = 15;
                if(mp[10]>0) {
                    tmp-=10;
                    mp[10]--;
                }
                while(tmp>0) {
                    tmp-=5;
                    mp[5]--;
                }
                
            }
            if(mp[5]<0) return false;
        }
        return true;
#endif
#if 1
//每次找零都确认是否会产生false，如果所有找零都没出现false，则可返回true
        int five = 0, ten = 0;
        for(const auto& bill : bills) {
            if (bill == 5) five++;
            else if(bill == 10 && five>0) five--, ten++;
            else if(ten>0 && five>0) five--, ten--;
            else if (five > 2) five-=3;
            else return false;
        }
        return true;    
#endif
    }
};
// @lc code=end

