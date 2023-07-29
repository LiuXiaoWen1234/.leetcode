/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());


        long tmp;
        int c, d;


        for(int a=0; a<nums.size()-1; a++){
            //A去重
            if(a>0 && nums[a]==nums[a-1]){
                continue;
            }
            for(int b=a+1; b<nums.size(); b++){
                //B去重
                if(b>(a+1) && nums[b] == nums[b-1]){
                    continue;
                }

                c = b+1;
                d = nums.size() - 1;

                while(c < d){
                    //!!!一直报错显示int超出边界
                    tmp = (long)nums[a] + nums[b] + nums[c] + nums[d];
                    if(tmp > target) d--;
                    else if(tmp < target) c++;
                    else {
                        result.push_back(vector<int>{nums[a],nums[b],nums[c],nums[d]});

                        //c去重和d去重
                        while(nums[d]==nums[d-1] && c < d) d--;
                        while(nums[c]==nums[c+1] && c < d) c++;
                        

                        c++;
                        d--;
                    }
                    

                }
                
                

            }
        }

        return result;
    }
};
// @lc code=end

