/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //由小到大排序
        sort(nums.begin(), nums.end());

        //三个指针start，mid，end
        int end ;
        int mid ;
        for(int start=0; start<nums.size()-1; start++){
            //若是最小的数都大于0
            if(nums[start]>0){
                return result;
            }
            // 对a去重
            if(start>0 && nums[start]==nums[start-1]){
                continue;
            }

            end = nums.size()-1;
            mid = start + 1;
            while(mid<end){
                
                if(nums[start] + nums[mid] + nums[end] > 0){
                    end--;
                }else if(nums[start] + nums[mid] + nums[end] < 0){
                    mid++;
                }else{
                    result.push_back(vector<int>{nums[start], nums[mid], nums[end]});
                    //对bc去重
                    while(mid<end && nums[end]==nums[end-1]) end--;
                    while(mid<end && nums[mid]==nums[mid+1]) mid++;
                    //找到答案时，双指针收缩
                    end--;
                    mid++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

