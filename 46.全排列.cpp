/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> nums){
        if(nums.size()==0){
            result.push_back(path);
            return;
        } 

        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            path.push_back(nums[i]);
            nums.erase(nums.begin()+i);//删除该元素进入下一层回溯
            backtracking(nums);
            nums.insert(nums.begin()+i, temp);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums);
        return result;

    }
};
// @lc code=end

