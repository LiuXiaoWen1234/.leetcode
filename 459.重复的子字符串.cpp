/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    void getNext(string& s, int* next){
        int j = -1;
        next[0] = j;  //i等于0，已赋值
        for (int i=1; i<s.size(); i++){
            while(j>=0 && s[j+1]!=s[i]){
                j = next[j];
            }
            if(s[j+1]==s[i]){
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int s_size = s.size();
        int next[s_size];
        getNext(s, next);

            //计算最长相同前后缀与字符串之差
        int temp = s_size - 1 - next[s_size -1 ];
        if(next[s_size -1 ]!=-1 && s_size % temp==0){
            return true;
        }
        return false;

    }
};
// @lc code=end

