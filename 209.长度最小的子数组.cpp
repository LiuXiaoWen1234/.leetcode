/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum =0;
        int len = 0;
        int result = INT32_MAX;
        int j = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                len = (i - j) + 1;
                result = result<len?result:len;
                sum -= nums[j++];
            }
        }

        return result==INT32_MAX?0:result;
        
    }
};
// @lc code=end

