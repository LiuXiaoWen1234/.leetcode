/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={};


        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0; i<t.size(); i++){
            arr[t[i]-'a']--;
        }
        for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

