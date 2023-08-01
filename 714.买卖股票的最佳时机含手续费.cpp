/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int prices_size = prices.size();
        if(prices_size==1 || (prices_size==2 && prices[0] >= prices[1])) return 0;

        vector<int> dp1(prices_size, 0); //持有股票
        vector<int> dp2(prices_size, 0); //不持有股票

        dp1[0] = -prices[0]-fee;
        dp2[0] = 0;
        
        for(int i=1; i<prices_size; i++){
            dp1[i] = max(dp1[i-1], dp2[i-1]-prices[i]-fee);
            dp2[i] = max(dp2[i-1], dp1[i-1]+prices[i]);
        }

        return dp2[prices_size -1];

    }
};
// @lc code=end

