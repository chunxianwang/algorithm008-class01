/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
#if 0
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
};
#endif
#if 1
int n;
int m;
// 记录（x，y）位置处最小距离是多少
struct pos {
    pos (int x, int y, int dis) : x(x), y(y), dis(dis){}
    int x;
    int y;
    int dis;
};

// 关键：由于对角线移动 比 水平、垂直移动的距离更远而花费一样，所以以如下方法排序优先级；
// 例如：（0,0） -> （2,5）的最优预期花费就是max(2 - 0, 5 - 0)
bool operator < (const pos A, const pos B) {
    return max(n - 1 - A.x, m - 1 - A.y) + A.dis - (max(n - 1 - B.x, m - 1 - B.y) + B.dis) >= 0;
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return -1;
        }
        n = grid.size();
        m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return -1;
        }
        if (n == 1 && m == 1) {
            return 1;
        }
        priority_queue<pos> q;
        pos start(0, 0, 1);
        q.push(start);
        // 拥塞路径加入closeList
        vector<bool> closeList(n * m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    closeList[i * m + j] = true;
                }
            }
        }
        // 不需要记录父节点，故openList只保存最小花费
        vector<int> openList(n * m, 0);
        openList[0] = 1;
        // 八个移动方向
        vector<vector<int>> mov {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, 0}, {0, -1}, {-1, -1}};
        while (!q.empty()) {
            pos cur = q.top();
            q.pop();
            int curIdx = cur.x * m + cur.y;
            closeList[curIdx] = true;
            for (int k = 0; k < 8; ++k) {
                int xx = cur.x + mov[k][0];
                int yy = cur.y + mov[k][1];
                int nextIdx = xx * m + yy;
                if (0 <= xx && xx < n && 0 <= yy && yy < m && !closeList[nextIdx]) {
                    if (xx == n - 1 && yy == m - 1) {
                        return openList[curIdx] + 1;
                    }
                    // 没有到走过改点或者当前的路线更优
                    if (openList[nextIdx] == 0 || openList[nextIdx] > openList[curIdx] + 1) {
                        openList[nextIdx] = openList[curIdx] + 1;
                        pos next(xx, yy, openList[curIdx] + 1);
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
#endif
// @lc code=end