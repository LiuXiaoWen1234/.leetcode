/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {       
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while(cur->next!=nullptr && cur->next->next != nullptr){
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            cur = cur->next->next;
        }
        return dummyNode->next;
    }
};
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {       
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        ListNo
        de* pre;
        while(cur->next!=nullptr && cur->next->next != nullptr){
            pre = cur->next;

            cur->next = pre->next;
            pre->next = cur->next->next;
            cur->next->next = pre;

            cur = pre;
        }
        return dummyNode->next;
    }
};

// @lc code=end

