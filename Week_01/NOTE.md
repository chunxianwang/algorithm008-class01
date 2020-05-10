#算法与数据结构学习笔记（更新ing）
参考其它同学笔记，优化每周更新笔记格式
笔记功能：
1. 总结本周学习完成情况
2. 总结本周重点知识点
3. 听课笔记，记录知识点，后续整理成专题笔记

week1：数组、链表、跳表，栈、队列、优先队列和双端队列
####知识点
* [算法时间复杂度和空间复杂度专题笔记](算法时间复杂度和空间复杂度.md)
### 链表
链表中节点的定义
```c++
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}   //初始化当前节点的值为x，指向空
};
```
链表数据的操作，两种方式：
1.按照一定的要求，重新串起已存在的节点，形成新的链表；
2.新定义一系列新节点，并串起来得到全新的链表；

无论如何，都是从一下操作起始
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


####参考内容
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



