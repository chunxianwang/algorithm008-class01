/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */



# include<vector>
using namespace std;
// @lc code=start
#if 0
//快速排序
class Solution {
private:
    int random_partition(vector<int>& nums, int l, int r) { //围绕标杆左右进行划拨（小于标杆，放左侧；大于标杆，放右侧）
        //随机选定标杆，放到最右侧；
        int k = rand() % (r-l+1)+l;  
        swap(nums[r], nums[k]); 
        int pivot = nums[r];
        
        //比较标杆据，进行左右划分
        int i = l-1;   //小于pivot数据的存放位置
        for (int j=l; j<=r-1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;    //i+1等于下一个小于pivot数据的存放位置，j指向下一个待排序小于pivot的数据
                swap(nums[i], nums[j]);  //左边的大数和右边的小数进行位置互换
            }
        }
        int pivot_pos = i+1; //标杆的合适位置
        swap(nums[pivot_pos], nums[r]);  //把标杆放到合适位置
        return pivot_pos;
    }
    void random_quicksort(vector<int>& nums, int l, int r) {
        if (l<r) {  //退出递归
            int pos = random_partition(nums, l, r);  
            random_quicksort(nums, l, pos-1);
            random_quicksort(nums, pos+1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        random_quicksort(nums, 0, (int) nums.size()-1);
        return nums;
    }
};
#endif
# if 0
//归并
class Solution {
private:
    vector<int> merged;
    void mergeSort(vector<int>& nums, int L, int R) {
        if (L >= R) return;
        int mid = (L + R) >> 1;
        mergeSort(nums, L, mid);
        mergeSort(nums, mid + 1, R);
        int i = L, j = mid + 1, k = 0;
        while (i <= mid && j <= R) merged[k++] = (nums[i] < nums[j]) ? nums[i++] : nums[j++];        while (i <= mid) merged[k++] = nums[i++];
        while (j <= R) merged[k++] = nums[j++];
        for (int i = 0; i < R - L + 1; i++) nums[L + i] = merged[i];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        merged.resize(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
#endif

#if 1
//堆排序
//priority_queue 的push() 和 pop() 都是O(logN)的时间复杂度，N个元素，
//所以，整体时间复杂度是NO(logN);
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q; //小顶堆
        int len = nums.size();
        for (int i = 0; i< len; i++) {
            q.push(nums[i]);
        }
        for (int i = 0; i< len; i++) {
            nums[i] = q.top();
            q.pop();
        }
        return nums;
    }
};
#endif

// @lc code=end

