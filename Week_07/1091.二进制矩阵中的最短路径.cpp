/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
//方法一：普通广度优先 bfs
private:
    struct Node {
        int x;
        int y;
        int step;
        Node(int i, int j, int s) : x(i), y(j), step(s) {}
    };  
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<struct Node> q;
        int n = grid.size();
        if (n==0 || grid[0][0] || grid[n-1][n-1]) return -1;

        q.push(Node(0, 0, 1));
        grid[0][0] = 1;
        while (!q.empty()) {
            Node node = q.front();
            q.pop();

            if (node.x==n-1 && node.y==n-1) return node.step;
            for(int dx=-1; dx<=1; dx++) {
                for(int dy=-1; dy<=1; dy++) {
                    int i = node.x + dx;
                    int j = node.y + dy;
                    if(i<0 || j<0 || i>=n || j>=n || grid[i][j]) continue;
                    q.push(Node(i, j, node.step+1));
                    grid[i][j] = 1;
                }
            }
        }
        return -1;
    }

//方法二: 

};
// @lc code=end

