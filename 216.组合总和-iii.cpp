/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int targetSum, int k, int curSum, int StartIndex){
        if(path.size()==k){
            if(curSum==targetSum) result.push_back(path);
            return;
        }
        if(curSum > targetSum) return;

        for(int i=StartIndex; i<=(9 - (k-path.size()) + 1) ; i++){
            path.push_back(i);
            backtracking(targetSum, k, curSum+i, i+1);
            path.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(n,k,0,1);
        return result;
        
    }
};
// @lc code=end

