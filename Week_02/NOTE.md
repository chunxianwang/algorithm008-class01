## 算法与数据结构笔记-week2

### 哈希表、映射、集合（hash_table、map、set）
**哈希映射：c++ unordered_map**
unordered_map是一个关联容器，用于存储通过键值和映射值的组合形成的元素。 键值用于唯一标识元素，映射值是与键值相关联的内容。键和值都可以是预定义或用户定义的任何类型。值的含义，也是用户自定义，如相应键的计数，相应键的权重...
* unordered_map内部使用哈希表实现，提供给映射的键被散列成哈希表的索引。
* 查询的时间复杂度：
  O(1)， 优于数映射；
  最坏的情况下，unordered_map退化成O(n）的时间复杂度。
* 常用函数：可用于unordered_map。 最有用的是 - operator =，operator []，empty()和size()，iterator的begin()和end()，find()和count()用于查找，insert()和erase()用于修改。 C++ 11库还提供了查看内部使用的桶数(bucket count)，桶大小(bucket size)以及使用的散列函数和各种哈希策略的函数，但它们在实际应用中不太有用。 我们可以使用Iterator迭代unordered_map的所有元素。 初始化，索引和迭代显示在以下示例代码中：
```c++
// C++ program to demonstrate functionality of unordered_map
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //声明
    unordered_map<string, double> umap;
    //赋值
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    //来自数组的赋值,统计数组中各种元素个有多少个
    vector<string> st(10,"a");
    for (auto n : st) umap[n]++;
    //插入
    umap.insert(make_pair("e", 2.718));
    //查询某个key的elements数量，注意不是value值，是map中某个key的数量
    int nums_PI = um.count("PI");
    //容器尺寸
    int sz = um.size();
    string key = "PI";
    //查询某key的iterator
    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n";
    //迭代器 起始和结束
    unordered_map<string, double>:: iterator itr;
    for (itr = umap.begin(); itr != umap.end(); itr++)
        //访问迭代器的键key 和 值value
        cout << itr->first << "  " << itr->second << endl;
}
```
相关题目：
[242. 有效的字母异位词](242.有效的字母异位词.cpp)
[49.字母异位词分组](49.字母异位词分组.cpp)
[1.两数之和](1.两数之和.cpp)
[299.猜数字游戏](299.猜数字游戏.cpp)
[350.两个数组的交集](350.两个数组的交集-ii.cpp)

###树、二叉树、二叉搜索树(tree\ binary-tree、binary-search-tree)
**空间换时间思想**：要想节省时间，就升维，二叉树就是在链表这个一维结构基础上，通过升维演化而来。
####二叉树
二叉树节点的定义：
```c++
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x), left(NULL), right(NULL){}
}
```
二叉树，三种遍历方式
1.pre-order,前序：根-左-右
2.in-order,中序：左-根-右
3.post-order,后序：左-右-根
![avatar](https://gitee.com/chunxianwang/ImageHost/raw/master/uPic/二叉树遍历.jpg)

用递归和非递归都可以实现遍历，递归实现较简单，c++代码如下：
前序遍历--递归
```c++
void PreOrder(TreeNode* root) {
    if (root != NULL) {
        cout << root->val << endl;
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
```
中序遍历--递归
```c++
void InOrder(TreeNode* root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->val << endl;
        InOrder(root->right);
    }
}
```
后序遍历--递归
```c++
void PostOrder(TreeNode* root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->val << endl;
    }
}
```
**用栈&迭代，实现前、中、后序遍历二叉树**
用二叉树基本单元结构描述实现思路
根节点A、左子树B和右子树C
<img src="https://gitee.com/chunxianwang/ImageHost/raw/master/uPic/binarytree.png" width=256 height=256 />

1.前序列遍历

    前序遍历思路：
    不断获取当前根节点，获取后马上访问根节点的值，
    根节点来源：初始化根节点，上次迭代中根节点的左子树，栈中的右子树
    栈的作用：寄存暂时来不及访问的右子树

    伪代码：

    初始化根节点
    枚举更新根节点，来自栈中暂存的各级右子树
        枚举更新根节点，来自上次循环中根节点的左子树
            访问根节点的值；
            栈中暂存右子树；
        根节点指向左子树
    根节点指向栈顶暂存的右子树，弹栈顶；
2.后序列遍历

    后序遍历思路：用前序遍历相似的方法，后序遍历与前序遍历对称，
    遍历完成后把结果进行逆序处理
    伪代码：
    枚举更新根节点，来自栈中暂存的各级左子树（前序是右子树）
        枚举更新根节点，来自上次循环中根节点的右子树（前序是左子树）
            输出根节点的值；
            栈中暂存左子树（前序是右子树）
        根节点指向右子树（前序是左子树）
    根节点指向栈顶暂存的左子树（前序是右子树），弹栈顶；
    结果序列逆序

3.中序遍历

    每到一个节点 A，因为根的访问在中间，将 A 入栈。
    然后遍历左子树，接着访问 A，最后遍历右子树。
    在访问完 A 后，A 就可以出栈了。因为 A 和其左子树都已经访问完成。
    伪代码：
    初始化根节点
    枚举更新根节点，来自栈中暂存各级根节点的右子树
        枚举更新根节点，来自上次循环中根节点的左子树
            栈中暂存右子树；
        根节点指向当前根的左子树
    根节点指向栈顶暂存根节点的右子树，弹栈顶；
    输出根节点的值；
    更新根节点为栈中弹出根节点的右子树
相关题目：
[94. 二叉树的中序列遍历](94.二叉树的中序遍历.cpp)
[144. 二叉树的前序列遍历](144.二叉树的前序遍历.cpp)
[145. 二叉树的后序列遍历](145.二叉树的后序遍历.cpp)
[104. 二叉树的最大深度](104.二叉树的最大深度.cpp)
[429.n叉树的层序遍历](429.n叉树的层序遍历.cpp)
[589.n叉树的前序遍历](589.n叉树的前序遍历.cpp)

二叉树无序，因此查询某个节点，需要遍历，因此时间复杂度是O(n)

####二叉搜索树
当二叉树有序时，称为二叉搜索树，也称有序二叉树：
1.左子树上所有节点的值，均小于它的根节点的值；
2.右子树上所有节点的值，均大于它的根节点的值；
3.以此类推：左右子树也分别为二叉查找树。
此时，中序遍历，是升序遍历。

查询、插入和删除节点，时间复杂度都是O(logn)
最差的情况下，树不平衡，退化程链表，时间复杂度变为O(n)

**思考题**
Q:树的面试题解法一般都是递归，为什么？
A:树本身节点的定义，就是以递归方式进行描述
### 堆和二叉堆
**定义**
堆(heap)，可以迅速找到一堆数中最大或者最小值的数据结构
根节点最大，称为大顶堆；根节点最小，称为小顶堆

**时间复杂度**
find-max：    O(1)
delete-max：  O(logN)
insert(create)：O(logN) 或 O(1)

**二叉堆是堆的一种常见且简单的实现；但并不是最优的实现**，如非波拉契堆和严格非波拉契堆

二叉堆插入节点：
1. 新元素先插到堆的尾部，
2. 不断和其父节点比较，如果大于父节点，则交换
3. 直到小于父节点；

二叉堆删除节点：
1. 堆尾元素替换到删除节点，
2. 不断地：左右子节点比较，且较大子节点交换
3. 直到大于左右子节点。

**C++ STL中的优先队列、堆**
STL中priority_queue的本质就是一个二叉堆
包含在头文件queue.h中
默认声明是大顶堆
priority_queue<int> q;//默认是大顶堆
priority_queue<int, vector<int>, greater<int> > q;//特别声明小顶堆，必须要在声明中指明数据类型、容器类型，比较方式（小顶堆）

STL中并没有把heap作为一种容器组件，heap的实现亦需要更低一层的容器组件（诸如list,array,vector）作为其底层机制。
Heap是一个类属算法，包含在algorithm头文件中。
```
#include<algorithm>
//四个函数
make_heap();
pop_heap();
push_heap();
sort_heap();
```
虽然STL中关于heap默认调整成的是大顶堆，但却可以让用户利用自定义的compare_fuction函数实现大顶堆或小顶堆。

相关题目：
[347.前k各高频元素](347.前-k-个高频元素.cpp)

sort时间复杂度 :O(NlogN)

### 图
图的属性
* Graph(V, E)
* V-vertex:点
  1.度-入度和出度
  2.点与点之间：是否连通
* E-edge:边
  1.有向和无向
  2.权重（变长）

图的实现方式：临接矩阵 adjacency matrix、临接链表 adjacency list

图的分类：
1.无向无权图
2.有向无权图
3.无向有权图
4.有向有权图

基于图的常见算法：      *待第四周补充*
DFS:depth first search
BFS:breadth first search


