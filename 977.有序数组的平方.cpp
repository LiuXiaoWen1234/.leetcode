/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int startNum = 0;
        int endNum = nums.size() - 1;
        vector<int> new_array(nums.size());

        
        for (int i=nums.size()-1; i>=0; i--){
            
            if(abs(nums[startNum]) > abs(nums[endNum])){
                new_array[i] = pow(nums[startNum++],2);
            }else{
                new_array[i] = pow(nums[endNum--],2);
            }

        }

        return new_array;

    }
};
// @lc code=end

