/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left= 0;
        int right = nums.size() - 1;
        
        while(left<= right){
            int middle = left + ((right - left)/2);
            if (target > nums[middle]){
                left = middle + 1;
            }else if (target < nums[middle]){
                right = middle - 1;
            }else{
                return middle;
            }
        }
        return left;

    }
};
// @lc code=end

