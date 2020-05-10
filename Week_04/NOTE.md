学习笔记

搜索的要求：遍历所有的点，保证每个点访问一次且仅访问一次。

![avatar](https://gitee.com/chunxianwang/ImageHost/raw/master/uPic/DFS和BFS.png)
深度优先搜索的访问顺序：0-1-3-4-2-5-6
广度优先搜索的访问顺序：0-1-2-3-4-5-6
深度优先vs广度优先（暂缓下探）
深度优先：**先下探再说，实在不行再返回到上层**，具体地：锚定一个父节点，访问其一个分支，紧接着下探到下一个分支，直到这下一个分支被访问完后，再访问被锚定父节点的另外一个分支；
广度优先：**先把本层遍历再下探，遍历时为下探作准备，即暂存信息**，具体地：锚定一个父节点，逐个访问其所有分支，在访问每个分支时，把每个分支的下一层分支信息暂存起来，等到这层的所有分支被访问完时，再取出这些所有暂存信息，实施和上述类似的操作。

## 深度优先DFS

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
非递归写法
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

## 广度优先BFS
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