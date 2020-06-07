/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
//定义一个完整的 并查集 类
class UF {
private: 
    // 存储一棵树
    vector<int> parent;
    // 记录树的“重量”
    vector<int> size;
public:
    int count;
    UF(int n) {
        count = n;
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void unionop(int p, int q) {
        //查询p、q所在集合的领头元素
        int rootP = find(p);
        int rootQ = find(q);
        
        //如果领头元素相等，说明它们已经属于同一个集合，
        if (rootP == rootQ)
            return;
        
        //如果领头元素不相等，那就进行合并；
        // 小树接到大树下面，进行平衡
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }
    //找某个元素所在集合的领头元素
    int find(int x) {
        while (parent[x] != x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];   //x的父结点，连接到了其父亲的父亲结点上
            x = parent[x];                   //更新x，指向父结点
        }
        return x;
    }
    int countop() {
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UF uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1)
                    uf.unionop(i, j);
            }
        }
        return uf.countop();
    }
};
// @lc code=end

