# 算法与数据结构笔记-week1: 数组、链表、跳表、栈和队列
[toc]

week1：数组、链表、跳表，栈、队列、优先队列和双端队列
附加：
* [算法时间复杂度和空间复杂度专题笔记](算法时间复杂度和空间复杂度.md)

### 数组 array
**时间复杂度**：
查询，O(1)
增加或删除元素，O(N)

### 链表 linked list
**时间复杂度**：
查询，O(N)
增加或删除元素，O(1)
-----
链表中节点的定义
```c++
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}   //初始化当前节点的值为x，指向空
};
```
-----
链表数据的操作，两种方式：
1.按照一定的要求，重新串起已存在的节点，形成新的链表；
2.新定义一系列新节点，并串起来得到全新的链表；

无论如何，都是从以下操作起始
```c++
ListNode* newhead = new ListNode(0, NULL);//定义新链表的头节点，在此头节点的next指针开始重新组织新链表
ListNode* currentnode = newhead;//定义当前操作节点
...//经过一系列基于currentnode的操作后
return newhead->next;//提交最终结果
```
补充链表的常规操作
新建节点、链表
删除节点
增加节点
### 跳表 skip list
当链表元素（value）有序的时候，跳表可有效降低查询的时间复杂度到O(logN)；
思想是：在链表的基础上升维来实现，间隔一个元素，形成一级索引，在一级索引基础上，再间隔一个元素，形成二级索引。。。
典型的空间换时间方法：因为空间复杂度提高了，增加了N个元素来存储升维的数据。
![avatar](https://gitee.com/chunxianwang/ImageHost/raw/master/uPic/跳表.png)
**时间复杂度**
查询 O(logN)，相比链表降低了。
增加或删除节点，O(logN),比链表增加了，因为要更新索引。

### 栈stack、队列、双端队列、优先队列
栈，先入后出， 查询和增删时间复杂度都是O(1)
队列，先入先出，查询和增删时间复杂度都是O(1)
双端队列 = 栈+队列，可先入先出，也可以先入后出

优先队列priority queue:按照元素优先级取出队列元素
插入操作O(1)
取出操作O(logN)，按照元素的优先级取出

### 参考内容
记录mind map中的陌生概念，及其参考文章
1. 顺序存储和链式存储
   https://www.jianshu.com/p/8293e061d4f9
2. 数据结构中的堆、栈和队列
   https://www.jianshu.com/p/5f148c3e4f7d
3. 散列表 hash table 哈希表
   https://www.cnblogs.com/acm-bingzi/p/hash.html
4. 数据结构堆
   https://www.jianshu.com/p/6b526aa481b1
5. 二叉树
   https://www.jianshu.com/p/29d340e38479
   https://www.jianshu.com/p/a47d6ed886c8
6. 图
   图概述：https://www.jianshu.com/p/bce71b2bdbc8
作业题目

### sort() 函数 自定义compare用法
* 两参数，默认升序排列
```c++
int a[] = {45, 6, 78, 9,102, 4};
sort(a.begin(), a.end()) //默认升序排列
```

* 三参数，自定义升、降序排列
```c++ 
//compare 模板
bool compare(int a, int b) {
   return a < b;  //升序
   return a > b;  //降序
}
int a[] = {45, 6, 78, 9,102, 4};
sort(a, a+6, compare)
```

* 三参数，容器
  容器，可直接用greater<type>()或less<type>()排序
  ```c++
  int a[] = {45, 6, 78, 9,102, 4};
  vector<int> arr(a, a+6);
  sort(arr.begin(), arr.end(), greater<int>());
  sort(arr.begin(), arr.end(), less<int>());
  ```
  ```c++
    std::sort(detectors.begin(), detectors.end(), [&](const VisionObject& a, const VisionObject& b) -> bool {
              return a.bbox_.y + a.bbox_.height - a.camera_index_ * height_ >
                     b.bbox_.y + b.bbox_.height - b.camera_index_ * height_;
            });  //在sort内部定义compare
  ```
* 两参数，class或struct
   在类内部重载<运算符，定义排序规则，升序或降序
  ```c++
  typedef struct student{
      char  name[20];
      int math;
      //按math降序排列
      inline bool operator < (const student &x) const {   //重载 < 运算符号
         return math > x.math; //降序
         return math < x.mathl //升序
      }
   }Student;
   main(){
      Student a[4]={{"apple",67},{"limei",90},{"apple",90}};
      sort(a,a+3);
   }
  ```
  
  
### 堆栈概念总结
  堆(stack)栈(heap)出现在两个地方：计算机内存结构 和 数据结构，有联系也有差别，在此进行总结

#### 内存中的堆区、栈区
* 栈区（stack）：由编译器自动分配释放，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。先入后出。
* 堆区（heap）：一般由程序员分配释放，若程序员不释放，程序结束时可能由操作系统回收。注意它与数据结构中的堆是两回事，其分配方式倒是类似于链表。
  
#### 数据结构中的堆 和 栈
* 栈：先入后出的数据结构
* 堆：堆是一种经过排序的树形数据结构，每个节点都有一个值，通常我们所说的堆的数据结构是指二叉树。所以堆在数据结构中通常可以被看做是一棵树的数组对象。而且堆需要满足一下两个性质：
（1）堆中某个节点的值总是不大于或不小于其父节点的值；
（2）堆总是一棵完全二叉树
