/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

// class Solution {
// public:
//     bool isValid(string s) {

//         stack<char> result;
//         for(int i=0; i<s.size(); i++){
//             if(s[i]=='(') result.push(')');
//             else if(s[i]=='[') result.push(']');
//             else if(s[i]=='{') result.push('}');
//             else if(!result.empty() && result.top()==s[i]) result.pop();
//             else    return false;
//         }
//         return result.empty();
//     }
// };


class Solution {
public:
    bool isValid(string s) {

        stack<char> result;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') result.push(s[i]);
            else if(!result.empty() && abs(int(result.top())-int(s[i]))<3) result.pop();
            else    return false;
        }
        return result.empty();
    }
};
// @lc code=end

