/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX-1);
        dp[0] = 0;

        //背包问题，物品为i*i，背包容量为n，将其完全装满最少物品数
        for(int i=1; i*i<=n; i++){
            int temp = i*i;
            for(int j=temp; j<=n; j++){
                dp[j] = min(dp[j], dp[j-temp]+1);
            }
        }
           
        return dp[n];
    }
};
// @lc code=end

