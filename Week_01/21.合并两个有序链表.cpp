/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        #if 1
        ListNode *newhead = new ListNode(0); //新建一个链表节点指针，作为目标链表head
        ListNode *currentnode = newhead;  //指向目标链表head
        while(l1 && l2)    //遍历链表，直到某个链表结束，即指向了Null
        {
            if(l1->val < l2->val)   //比较两连表节点值的大小
            {
                currentnode->next = l1;     //目标链表指向值较小的链表节点
                l1 = l1->next;      //指向下一个节点
            }
            else{
                currentnode->next = l2;
                l2 = l2->next;
            }
            currentnode = currentnode->next;     //指向下一个节点
        }
        currentnode->next = l1 ? l1 :l2;//处理l1或者l2有剩余的情况，指向剩余部分
        return newhead->next;
        #endif
    }
};
// @lc code=end

