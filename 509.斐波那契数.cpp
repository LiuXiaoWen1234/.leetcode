/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        vector<int> dp(2);
        dp[0]=0;
        dp[1]=1;
        if(n<=1) return dp[n];
        for(int i=2; i<=n; i++){
            dp[1] = dp[0] + dp[1];
            dp[0] = dp[1] - dp[0];
        }
        return dp[1];
    }
};
// @lc code=end

