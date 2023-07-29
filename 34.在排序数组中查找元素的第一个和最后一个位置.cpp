/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size() - 1;

        while(left <= right){
            int middle = left + ((right - left)/2);
            if (nums[middle] < target){
                left = middle + 1;
            }else if (nums[middle] > target){
                right = middle - 1;
            }else{
                //找到目标值后开始线性查找,这里改进为继续二分查找
                int start = middle;
                int end = middle;
                while((start>=0)&&(nums[start]==target)){
                     start = start - 1;
                 }
                while((end<nums.size())&&(nums[end]==target)){
                    end = end + 1;
                }
                return vector<int>{start +1 , end - 1};
                //return vector<int>{start , middle};
            }
        }
        return vector<int>{-1,-1};
    }
};
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int rightBorder = getRightBorder(nums, target);//返回第一个比target大的数
        int leftBorder = getLeftBorder(nums, target);
        //target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2
        //或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
        if (rightBorder==-2||leftBorder==-2){
            return {-1,-1};
        }
        //例如数组{3,6,7},target为6，此时应该返回{1, 1}
        if((rightBorder - leftBorder)>1){
            return {leftBorder+1, rightBorder-1};
        }
        return {-1, -1};
    }


    //利用二分查找，寻召target的上边界即右边界
    int getRightBorder(vector<int>&nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; //记录rightBorder未被赋值的情况
        while(left<=right){
            int middle = left + ((right - left)/2);
            //若中间值比目标值大，则上界应该出现在左区间中
            if (nums[middle] > target){
                right = middle - 1;
            //上界在右区间中
            }else{//当nums[middle]==target的时候，更新left，以便得到target的右边界
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

    //利用二分查找，寻找target的下边界
    int getLeftBorder(vector<int>&nums, int target){
        int left=0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while(left <= right){
            int middle = left + ((right - left)/2);

            if (nums[middle] <target){
                left = middle + 1;
            }else{
                right = middle - 1;
                leftBorder = right;
            }
        }
        return leftBorder;
    }


    
};

// @lc code=end

