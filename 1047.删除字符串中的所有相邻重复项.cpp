/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> result;
        for(char charr : s){
            if(result.empty() || charr!=result.top()){
                result.push(charr);
            }else{
                result.pop();
            }
        }

        string str;
        while(!result.empty()){
            str+=result.top();
            result.pop();
        }
        reverse(str.begin(), str.end());
        return str;


    }
};
// @lc code=end

