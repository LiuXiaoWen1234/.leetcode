/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> instack;
    stack<int> outstack;

    MyQueue() {

    }
    
    void push(int x) {
        instack.push(x);

    }
    
    int pop() {
        if(outstack.empty() == true){
            while(instack.empty()==false){
                outstack.push(instack.top());
                instack.pop();
            }
        }
        int result = outstack.top();
        outstack.pop();
        return result;
    }
    
    int peek() {
        //调用上面的pop方法；
        int a = this->pop(); //直接使用已有的pop函数
        outstack.push(a);
        return a;

    }
    
    bool empty() {
        if(outstack.empty()==true && instack.empty()==true) return true;
        else return false;

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

