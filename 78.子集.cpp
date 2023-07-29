/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    //以[1,2,3]为例，第一次回溯找到包含元素1的所有子集，第二次回溯包含元素2向后所有子集
    void backtracking(vector<int>& nums, int startIndex){
        result.push_back(path);
        //结束条件暂定
        if(startIndex >= nums.size()) return;


        //单层回溯逻辑
        for(int i=startIndex; i<nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();

        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        
        backtracking(nums, 0);
        return result;

    }
};
// @lc code=end

