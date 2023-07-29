/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0]==b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++){
            vector<int> temp = result.back();
            if(intervals[i][0]<=temp[1]){
                 result.pop_back();
                temp[1] = max(intervals[i][1], temp[1]);
                result.push_back(temp);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end

