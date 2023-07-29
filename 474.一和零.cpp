/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp (m+1, vector<int>(n+1,0));

        for(int i = 0; i<strs.size(); i++){
            int zero = 0, one = 0;
            for(char c:strs[i]){
                if(c == '1') one++;
                else if( c== '0') zero++;
            }
           
            for(int s=m; s>=zero; s--){
                for(int t=n; t>=one; t--){
                    dp[s][t] = max(dp[s][t], dp[s-zero][t-one]+1);
                }
            }
        }

        return dp[m][n];

    }
};
// @lc code=end

