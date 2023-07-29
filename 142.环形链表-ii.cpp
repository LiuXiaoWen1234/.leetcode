/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        //fast指针迈两步，slow指针迈一步，进入环后fast指针追赶slow指针，并且每进行一步fast向slow靠近一个节点
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL && fast->next->next!=slow->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        

        //不存在环直接返回-1,若存在则找到交汇点
        if(fast==NULL || fast->next==NULL || fast->next->next==NULL){
            return NULL;
        }else{
            fast = fast->next->next;
        }

        //存在环的话，fast和slow相遇点与链表起始点到环起点的距离相等
        ListNode* index1 = fast;
        ListNode* index2 = head;
        while(index1 != index2){
            index1 = index1->next;
            index2 = index2->next;
        }
        return index1;        
    }
};
// @lc code=end

