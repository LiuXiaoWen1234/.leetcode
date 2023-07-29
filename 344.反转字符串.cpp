/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while(i<j){
            //注意swap函数的实现方法：
            //a^=b:a=a^b b^=a:b=b^a=b^(a^b)=a^0=a a^=b:a=a^b=(a^b)^a=b
            swap(s[i], s[j]);
            i++;
            j--;
        }

    }
};
// @lc code=end

