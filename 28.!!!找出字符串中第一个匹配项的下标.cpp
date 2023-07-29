/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    void getNext(string& s, int* next){
        int j = -1; //j指向前缀末尾
        next[0] = j; //i取0时已经赋值
        //i指向后缀末尾
        for(int i=1; i<s.size(); i++){
            //若不相等，j需要回退
            while(j>=0 && s[j+1]!=s[i]){
                j = next[j];
            }

            if(s[i] == s[j+1]){
                j++;
            }
            next[i]=j;
        }
    }

    int strStr(string haystack, string needle) {
        int len_needle = needle.size();
        if(len_needle == 0){
            return 0;
        }
        

        int next[len_needle];
        getNext(needle, next);

        int j=-1;
        for(int i=0; i<haystack.size(); i++){

            while(j>=0 && needle[j+1]!=haystack[i]){
                j = next[j];
            }
            if(needle[j+1]==haystack[i]){
                j++;
            }
            if(j==needle.size()-1){
                return (i-needle.size()+1);
            }

        }
        return -1;
    }
};
// @lc code=end

