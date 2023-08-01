/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_size = prices.size();
        if(prices_size==1 || (prices_size==2 && prices[0] >= prices[1])) return 0;

        vector<int> dp1(prices_size, 0); //持有股票
        vector<int> dp2(prices_size, 0); //不持有股票

        dp1[0] = -prices[0];
        dp2[0] = 0;
        dp1[1] = max(-prices[0], -prices[1]);
        dp2[1] = max(dp2[0], dp1[0]+prices[1]);

        for(int i=2; i<prices_size; i++){
            dp1[i] = max(dp1[i-1], dp2[i-2]-prices[i]);
            dp2[i] = max(dp2[i-1], dp1[i-1]+prices[i]);
        }

        return dp2[prices_size -1];
    }
};
// @lc code=end

