/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //计算两个链表的长度
        ListNode* curA = headA;
        ListNode* curB =headB;
        int countA = 0;
        int countB = 0;
        while(curA!=NULL){
            curA = curA->next;
            countA++;
        }
        while(curB!=NULL){
            curB = curB->next;
            countB++;
        }

        ListNode* fast = countA >= countB? headA : headB;
        ListNode* slow = countA < countB? headA : headB;
        int temp = abs(countA-countB);
        while(temp){
                fast = fast->next;
                temp--;
        }
        

        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast==NULL){
            return NULL;
        }else{
            return fast;
        }
        
    }
};
// @lc code=end

