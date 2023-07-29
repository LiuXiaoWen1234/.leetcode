/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:

    //定义一个单向链表
    struct LinkeNode{
        int val;
        LinkeNode* next;
        LinkeNode(int val):val(val), next(nullptr){}
    };

    MyLinkedList() {
        _dummyHead = new LinkeNode(0);//定义虚拟头节点
        _size = 0;
    }
     

    void addAtIndex(int index, int val) {
        if(index<0) index=0;
        if(index>_size-1) return;

        LinkeNode* newNode = new LinkeNode(val);
        LinkeNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }


    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index>(_size - 1) || index < 0) {
            return -1;
        }
        LinkeNode* cur = _dummyHead->next;
        while(index--){ // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkeNode* newNode = new LinkeNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkeNode* cur = _dummyHead;
        while(cur->next!=nullptr){
            cur = cur->next;
        }

        LinkeNode* newNode = new LinkeNode(val);
        cur->next = newNode;
        _size++;

    }
    

    
    void deleteAtIndex(int index) {
        if(index > _size-1 ||index <0){
            return;
        }
        LinkeNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        LinkeNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;

    }

private:
    int _size;
    LinkeNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

