/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;//备用队列
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    //弹出最顶层元素
    int pop() {
        int size = que1.size();
        int temp;
       //弹出前面n-1个元素
        while(size>1){
            temp = que1.front();
            que2.push(temp);
            que1.pop();
            size--;
        }
        temp = que1.front();
        que1.pop();

        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        return temp;
    }
    
    int top() {
        
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();

    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

