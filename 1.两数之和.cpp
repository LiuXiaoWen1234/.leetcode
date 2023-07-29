/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        int tmp;

        for(int i=0; i<nums.size(); i++){
            tmp = target - nums[i];
            auto tmp_result = umap.find(tmp); //注意unordered_map的find前面是auto
            if(tmp_result!=umap.end()){
                return {tmp_result->second, i}; //访问key对应的value，用->second
            }else{
                umap.insert({nums[i], i}); //注意map.insert({key,value})
            }
        }
        return {}; //return空也是大括号
    }
};
// @lc code=end

