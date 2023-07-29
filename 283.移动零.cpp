/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start

/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for(int slow=0; slow<nums.size(); slow++){
            //如果slow指到了nums的最后一个元素
            if(slow==nums.size()-1){
                return;
            } 
            //找到slow==0的位置
            else if(nums[slow]!=0 && slow<nums.size()-1){
                continue;
            //利用fast找到第一个不为0的位置
            }else{
                int fast=slow+1;
                while(fast<nums.size() && nums[fast]==0){
                    fast++;
                }
                if(fast<nums.size()){
                    nums[slow]=nums[fast];
                    nums[fast]=0;
                }else{
                    nums[slow]=0;
                }
                
            }
        }

    }
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size()==0){
            return;
        }

        int j=0;
        for (int i=0; i<nums.size(); i++){
            //当前元素不为0就把它交换到左边，等于0的交换到右边
            if(nums[i]!=0){
                int temp = nums[j];
                nums[j++] = nums[i];
                nums[i] = temp;
            }
        }

    }
};
// @lc code=end

