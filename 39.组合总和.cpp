/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tempresult;
    void backtracking(vector<int> candidates, int target, int sum, int startIndex){
        if(sum==target){
            result.push_back(tempresult);
            return;
        }

        for(int i=startIndex; i<candidates.size() && sum+candidates[i]<=target; i++){
            tempresult.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i], i);
            tempresult.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        tempresult.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
        
    }
};
// @lc code=end

