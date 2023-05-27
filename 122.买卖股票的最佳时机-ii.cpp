/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int totalprofit =0;
     int buyPrices = -1; 
     for(int i=0; i<prices.size()-1; i++){
        //决定买入的条件：第二天比第一天价格高
        if(buyPrices==-1 && prices[i]<prices[i+1]){
            buyPrices = prices[i];
            continue;
        }

        //决定卖出的条件：第二天价格比买入的高且第三天不会更高
        if(buyPrices!=-1 && prices[i]>buyPrices && prices[i+1]<prices[i]){
            totalprofit  += prices[i] - buyPrices;
            buyPrices  = -1;
        }
     }

    if(buyPrices!=-1) totalprofit += prices[prices.size()-1] - buyPrices;
    return totalprofit;
    }
};
// @lc code=end

