学习笔记

搜索的要求：遍历所有的点，保证每个点访问一次且仅访问一次。

![avatar](https://gitee.com/chunxianwang/ImageHost/raw/master/uPic/DFS和BFS.png)
深度优先搜索的访问顺序：0-1-3-4-2-5-6
广度优先搜索的访问顺序：0-1-2-3-4-5-6
深度优先vs广度优先（暂缓下探）
深度优先：**先下探再说，实在不行再返回到上层**，具体地：锚定一个父节点，访问其一个分支，紧接着下探到下一个分支，直到这下一个分支被访问完后，再访问被锚定父节点的另外一个分支；
广度优先：**先把本层遍历再下探，遍历时为下探作准备，即暂存信息**，具体地：锚定一个父节点，逐个访问其所有分支，在访问每个分支时，把每个分支的下一层分支信息暂存起来，等到这层的所有分支被访问完时，再取出这些所有暂存信息，实施和上述类似的操作。

## 树结构遍历--BFS、DFS
### 深度优先DFS模板

递归模板
```
visited = set() 

def dfs(node, visited):
    if node in visited: # terminator
    	# already visited 
    	return 

	visited.add(node) 

	# process current node here. 
	...
	for next_node in node.children(): 
		if next_node not in visited: 
			dfs(next_node, visited)
```
非递归模板
```
def DFS(self, tree): 

	if tree.root is None: 
		return [] 

	visited, stack = [], [tree.root]

	while stack: 
		node = stack.pop() 
		visited.add(node)

		process (node) 
		nodes = generate_related_nodes(node) 
		stack.push(nodes) 

	# other processing work 
	...
```

### 广度优先BFS模板
广度优先：锚定一个父节点，逐个访问其所有分支，在访问每个分支时，把每个分支的下一层分支信息暂存起来，等到这层的所有分支被访问完时，再取出这些所有暂存信息，实施和上述类似的操作。

```
def BFS(graph, start, end):
    visited = set()
	queue = [] 
	queue.append([start]) 

	while queue: 
		node = queue.pop() 
		visited.add(node)

		process(node) 
		nodes = generate_related_nodes(node) 
		queue.push(nodes)

	# other processing work 
	...
```
【相关题目】
[二叉树的层序遍历]


## 二分法模板
使用二分法的前提假设：
* 目标函数单调性（单调递增或递减）
* 有左右边界（bounded）--保证不以无穷远处为起点，进行二分
* 能通过索引访问（index accessible）

```c++
int left = 0 , right = len(array) - 1;
while left <= right: 
	  int mid = (left + right) / 2 
	  if array[mid] == target: 
		    # find the target!! 
		    break or return result 
	  elif array[mid] < target: 
		    left = mid + 1 
	  else: 
		    right = mid - 1
```
## 贪心算法
贪心算法：在每一步都是找当前状态的最优（即找到对当前最有利的选项），从而**希望**找到全局最优

**贪心 vs 动态规划**
贪心 只对当前步骤选择最优，不能回退
动态规划：保存每一步的结果，可以用以前结果对当前进行选择，有回退功能；

**贪心算法适用场景**
问题能分解成子问题，子问题的最优解能等价于整个问题的最优解

## 总结容器 set VS map, unordered_set/map
* **红黑树实现**
  set和map都是基于红黑树实现，都是常用的数据容器
  note：想了解红黑树？请移步到：[红黑树（一）之：原理和算法详细介绍](https://www.cnblogs.com/skywang12345/p/3245399.html#a2)
* **set 和 map的区别**
  set:集合，容器中存放着键；迭代器（保存着键）是const，不允许修改；不可下标访问
  map:映射，容器中存放着键-值对；迭代器中key不能修改，value能被修改；可以下标访问value，通过map_element[key]的方式得到key对应的value

* **unordered_set/map**
  unordered_前缀表示用hash_table哈希来实现相关容器
  unordered_set 和 unordered_map的常见操作函数：
  1. find(key)，返回包含key的迭代器，有，返回迭代器；没有，返回迭代器unordered_set uset.end() 或 unordered_map umap.end()，可通过判断uset(key) == uset.end();判断set中不包含key。
  2. count(key)，返回是否有包含key的迭代器，有，返回1；没有，返回0。
  3. erase(key)，删除
  4. **umap.insert(std::make_pair(key, value))** 或 uset.insert(key) ，插入

