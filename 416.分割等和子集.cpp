/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumNums = accumulate(nums.begin(), nums.end(), 0);
        int halfSumNums = 0;
        if(sumNums%2==1){return false;}
        else halfSumNums = sumNums/2;

        vector<int> dp(halfSumNums+1, 0);
        for(int i=0; i<nums.size(); i++){
            for(int j=halfSumNums; j>=nums[i]; j--){
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }

        return dp[halfSumNums]==halfSumNums?true:false;
    }
};
// @lc code=end

