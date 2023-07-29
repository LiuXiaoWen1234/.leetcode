/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ran[26] = {0};
        for(char str:ransomNote){
            ran[str-'a']++;
        }

        for(char str:magazine){
            ran[str-'a']--;
        }

        bool result = true;
        for(int i:ran){
            if(i>0){
                result = false;
            }
        }
        return result;

    }
};
// @lc code=end

