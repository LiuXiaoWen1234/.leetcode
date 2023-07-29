/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int fun(vector<int>& nums, int start, int end){
        if(start == end) return nums[start];
        if(end - start == 1) return max(nums[start], nums[end]);

        vector<int> dp(end-start+1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for(int i=start+2; i<=end; i++){
            dp[i-start] = max(dp[i-start-1], dp[i-start-2]+nums[i]);
        }
        return dp[end-start];
    }


    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int result1 = fun(nums, 1, nums.size()-1);
        int result2 = fun(nums, 0, nums.size()-2);
        

        return max(result1, result2);
    }
};
// @lc code=end

