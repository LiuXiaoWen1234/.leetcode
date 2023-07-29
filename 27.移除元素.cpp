/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0; 
        int right = nums.size()-1;

        while(left <= right){
            //从左侧搜索等于val的数组下标值,避免left在寻找过程中超过right
            while(left<=right && nums[left]!=val){
                left = left + 1;
            }
            //从右侧索引不等于val的数组下标值
            while(left<=right && nums[right]==val){
                right = right - 1;
            }
            //当left和right同时指向val，right由于==val会减一，因此判断是必要的
            if (left<=right){
                nums[left++] = nums[right--];
            }
            

        }
         
         return left;
    }
};
// @lc code=end

