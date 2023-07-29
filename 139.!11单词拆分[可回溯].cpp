/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;



        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                string word = s.substr(j, i-j); //substr截取位置和截取个数
                //if(wordset.find(word)!=wordset.end() && dp[j])
                if(find(wordDict.begin(), wordDict.end(), word)!=wordDict.end() && dp[j])
                    dp[i]=true;
            }
           
        }

        return dp[s.size()];
    }
};
// @lc code=end

