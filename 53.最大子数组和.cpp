/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        //有正数有负数的数组，若sum<0则需抛弃
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > maxSum) maxSum = sum;
            if(sum < 0) sum = 0;
            
        }
        return maxSum;


    }
};
// @lc code=end

