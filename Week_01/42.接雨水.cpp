/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 * 以下题解和注释来自官方题解
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:

    int trap(vector<int>& height) {

#if 0
/*
暴力法
思路：对每个元素，找出下雨后能达到的最高位置，
等于两边最大高度的较小值，减去当前高度的值。
需要枚举每个位置，并对每个位置遍历左右遍所有位置，寻找左右最大高度的较小值。
因此:
时间复杂度是O(n^2)
空间复杂度是O(1)
*/
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = 0; j < i; j++) {
                max_left = max(max_left, height[j]);
            }
            for (int j=i+1; j < size; j++) {
                max_right = max(max_right, height[j]);
            }
            if (min(max_left, max_right) - height[i] > 0) {
                ans += min(max_left, max_right) - height[i];
            }
        }
        return ans;
#endif
#if 1
/*暴力法优化：
--空间换时间，降低复杂度
暴力法的核心是，对每个位置都要找出其左右的最高高度
优化思路：找每个位置的左侧最高高度时，
建立一个数组，存储每个元素的左侧最高高度，
仅需对比左侧相元素邻高度和它的左侧最高高度，就能得出当前元素左侧最高高度；
没必要每次都从最左侧开始比较，找最高高度。
右侧最高高度，亦然。空间换时间的典型思路。
时间复杂度O(n)
空间复杂度O(n)
*/
        if(height.size() == 0) return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i-1], left_max[i-1]);
        }
        right_max[size - 1] = height[size-1];
        for(int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i+1], right_max[i+1]);
        }
        for (int i = 1; i < size-1; i++) {
            ans += max(min(left_max[i], right_max[i]) - height[i], 0);
        }
        return ans;
#endif

#if 0
/*
栈的方法，
用栈来保存可能形成低洼区的信息，查找低洼区
我们在遍历数组时维护一个栈。
如果当前的条形块小于或等于栈顶的条形块，将条形块的索引入栈，
意思是当前的条形块被栈中的前一个条形块界定，属于待形成的低洼区。
如果发现一个条形块长于栈顶，可以确定栈顶的条形块被当前条形块和栈的前一个条形块界定，形成了一个地洼区，
因此可以弹出栈顶元素并且累加答案得到结果。
时间复杂度：O(n)。单次遍历 O(n) ，每个条形块最多访问两次（由于栈的弹入和弹出），
并且弹入和弹出栈都是O(1) 的。
空间复杂度：O(n)。 栈最多在阶梯型或平坦型条形块结构中占用O(n) 的空间。
*/
        int ans = 0, current = 0;
        stack<int> st;//存储元素索引号
        while (current < height.size()) { //遍历每个元素
            //内循环，判断形成了低洼区，处理已经形成了的低洼区
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();//作为低洼区的底部高度
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() -  1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            //判断没有形成低洼区，压入栈内
            st.push(current++);
        }
        return ans;
#endif

#if 0
/*
双指针--最优方法
时间复杂度O(n)
空间复杂O(1)
思路：左右指针遍历包抄，同时维护左右已遍历区域的最高边信息；
判断是否在左右指针的局部形成了低洼区；
*/
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;//用于记录左右已遍历元素的最高高度
        while (left < right) { //左右包抄循环
            if (height[left] < height[right]) { //左指针附近可能形成低洼区
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {  //右指针附近可能形成低洼区
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
#endif
    }
};
// @lc code=end