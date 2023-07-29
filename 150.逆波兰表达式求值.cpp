/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for(string str : tokens){
            if(str!="+" && str!="-" && str!="*" && str!="/") st.push(stoll(str));
            else{
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();


                if(str=="+") st.push(a+b);
                if(str=="-") st.push(b-a);
                if(str=="*") st.push(a*b);
                if(str=="/") st.push(b/a);
            }
        }
        return st.top();
    }
};
// @lc code=end

