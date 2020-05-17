/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

//两种方法：时间复杂度O(logM*N)
//1.二分查找，找目标所在行，再在这一行中，查找目标
//2.把m*n长的矩阵，视为长度为m*n的有序数组； 


// @lc code=start
#if 1
//方法1
class Solution {
    public:
    //因为每一行递增，每一列递增。所以我们可以从右上角往左下角找或者从左下角往右上角找。每次比较可以排除一行或者一列，时间复杂度为O(m+n)
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        if(matrix.empty()||matrix[0].empty())return 0;
        //从左下角上右上角寻找目标值
        int x=matrix.size()-1,y=0;
        while(x>=0&&y<matrix[0].size())
        {
            if(matrix[x][y]>target)x--;//[x,y]的值比目标值大，上移
            else if(matrix[x][y]<target)y++;//[x,y]的值比目标值小，右移
            else return true;
        }
        return false;
    }
};
#endif

#if 0
//方法2
class Solution {
  public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    // 二分查找
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
      pivotIdx = (left + right) / 2;
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];
      if (target == pivotElement) return true;
      else {
        if (target < pivotElement) right = pivotIdx - 1;
        else left = pivotIdx + 1;
      }
    }
    return false;
  }
};
#endif


// @lc code=end

