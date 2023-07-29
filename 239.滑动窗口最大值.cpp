/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
////--------私有类--------------////
private:
    class MyQueue{//单调列，从大到小
    public:
        deque<int> deq; //使用deque来实现单调列
        //返回当前出口元素
        int front(){
            return deq.front();
        }

        //弹出出口元素
        void pop(int x){
            if(!deq.empty() && x==deq.front()){
                deq.pop_front();
            }
        }

        //push
        void push(int x){
            while(!deq.empty() && x>deq.back()) deq.pop_back();
            deq.push_back(x);
        }
    };
    
////--------公有函数--------------////
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue deq;
        vector<int> result;
   
        for(int i=0; i<nums.size(); i++){
            deq.push(nums[i]);
            if(i>=k) deq.pop(nums[i-k]);
            if(i>=k-1) result.push_back(deq.front());


        }
    return result;
    }
};
// @lc code=end

