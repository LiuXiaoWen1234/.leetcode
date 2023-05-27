/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<int>& used){
        if(path.size()==nums.size()){
            result.push_back(path);
            return ;
        }

        int flag[21] = {0}; //横向数组，用于去重
        for(int i=0; i<nums.size(); i++){
            if(flag[nums[i]+10]==1) continue;

            if(used[i]) continue;
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i]=false;

            flag[nums[i]+10]=1;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<int> used(nums.size(),false);
        backtracking(nums, used);
        return result;

    }
};
// @lc code=end

