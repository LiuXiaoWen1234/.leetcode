/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result; //存放结果
    vector<int> path;//存放中间结果
    void backtracking(int n, int k, int startIndex){
        if(path.size()==k){
            result.push_back(path);
            return;
        }

        for(int i=startIndex; i <= n; i++){
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }

    }


public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;

    }
};
// @lc code=end

