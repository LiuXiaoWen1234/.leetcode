/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>&b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        //for(int i=0; i<points.size(); i++) cout<<points[i][0]<<points[i][1]<<endl;


        int result = 1;
        vector<int> temp = points[0];
        
        for(int i=1; i< points.size(); i++){
            //cout<<"temp:"<<temp[0]<<temp[1]<<endl;
             if(points[i][0]<=temp[1] && points[i][0]>=temp[0]){
                 temp[0] = points[i][0];
                 if(points[i][1]<=temp[1] && points[i][1]>=temp[0]){
                     temp[1] = points[i][1]; 
                 }
                 continue;
             }

             result++;
             temp[0] = points[i][0];
             temp[1] = points[i][1];
             //cout<<"result:"<<result<<endl; 
        }
        return result;
    }
};
// @lc code=end

