/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;

        for(int i=0; i<people.size();i++){
             int position = people[i][1];
             result.insert(result.begin()+position,people[i]);
        }
        return result;
    }
};
// @lc code=end

