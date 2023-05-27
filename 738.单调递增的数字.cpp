/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10) return n;
        vector<int> nums;
        while(n!=0){
            nums.push_back(n%10);
            n=n/10;
        } 

        //遍历顺序从低位数字到高位数字
        for(int i=1; i<nums.size(); i++){
            //当前数字 > 下一位数组
            if(nums[i]>nums[i-1]){
                nums[i]--;
                for(int j=i-1; j>=0; j--){
                    nums[j] = 9;
                }
            }  
        }

        int result = 0;
        for(int i=nums.size()-1; i>=0; i--){
            result = result*10 + nums[i];
        }

        return result;

    }
};
// @lc code=end

