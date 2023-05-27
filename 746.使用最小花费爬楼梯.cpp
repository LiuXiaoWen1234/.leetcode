/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(3);
        dp[0]=0;
        dp[1]=0;
        for(int i=2; i<=cost.size(); i++){
            dp[2]=min(dp[1]+cost[i-1], dp[0]+cost[i-2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[1];

    }
};
// @lc code=end

