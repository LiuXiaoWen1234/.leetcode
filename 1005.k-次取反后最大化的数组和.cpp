/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int sum = 0;
        //先将负数反转为正数
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0 && k>0){
                nums[i] *=-1;
                k--;
            }
            sum += nums[i]; 
        }
        //若k还有剩余且为奇数，偶数不需要管
        if(k%2==1) sum = sum - 2*nums[nums.size()-1];
        return sum;


    }
};
// @lc code=end

