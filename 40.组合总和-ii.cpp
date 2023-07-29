/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tempResult;
    void backtracking(vector<int> candidates, int target, int cursum, int startIndex, vector<int> used){
        if(cursum==target){
            result.push_back(tempResult);
            return;
        }

        for(int i=startIndex; i<candidates.size() && cursum + candidates[i] <= target; i++){
            if(i>0 && candidates[i]==candidates[i-1] && used[i-1]==0) continue;
            tempResult.push_back(candidates[i]);
            used[i]=1;
            backtracking(candidates, target, cursum+candidates[i], i+1, used);
            used[i]=0;
            tempResult.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        tempResult.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> used(candidates.size()); 
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};
// @lc code=end

