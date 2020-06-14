/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
#if 0
        int carry = 0;
        int sum = 0;
        ListNode* newhead = new ListNode(0, nullptr);//创建新链表头
        ListNode* nownode =newhead;  
        while(l1||l2||carry) {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10, nullptr);//不停地new ListNode，比较消耗时间
            nownode->next = node;
            nownode = nownode->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return newhead->next;//返回链表头指向的下一个节点
#endif
#if 1
        int carry = 0;
        int sum = 0;
        ListNode newhead(0, nullptr);  //直接定义对象
        ListNode* currentNode = &newhead;
        while (l1 || l2 || carry) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10, nullptr);  //定义对象指针
            currentNode->next = node;
            currentNode = currentNode->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return newhead.next;

#endif

#if 0
//国外高票代码，11行实现相同方法
        ListNode newhead(0, nullptr), *currentnode = &newhead;
        int carry = 0;
        while (l1 || l2 || carry) {
            std::cout<<carry<<std::endl;
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            currentnode->next = new ListNode(sum % 10);
            currentnode = currentnode->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return newhead.next;
#endif         
    }


};
// @lc code=end

