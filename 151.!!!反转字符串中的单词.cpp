/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    //移除多余空格
    void removespace(string& s){
        //快慢指针，快指针前面扫描，慢指针后面记录
        int slow = 0;
        for(int fast=0; fast<s.size(); fast++){
            if(s[fast]!=' '){
                if(slow!=0) s[slow++] = ' ';
                //单词记录
                while(s[fast]!=' ' && fast<s.size()){
                    s[slow++] = s[fast++];
                }
            }
        }
        return s.resize(slow);
    }

    void reverse(string& s, int start, int end){
        for(int i=start,j=end; i<j; i++,j--){
            swap(s[i], s[j]);
        }
    }




    string reverseWords(string s) {
        removespace(s);
        reverse(s, 0, s.size()-1);
        int j=0;
        for(int i=0; i<=s.size(); ++i){
            if(i == s.size()|| s[i]==' '){
                reverse(s, j, i-1);
                j = i+1;
            }

        }
        return s;
    }

};
// @lc code=end

