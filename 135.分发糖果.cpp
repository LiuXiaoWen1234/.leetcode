/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> result(ratings.size());
        //从前向后，右边孩子比左边大则多发一个糖果
        result[0] = 1;
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]) result[i]=result[i-1]+1;
            else result[i] = 1;
        }
        //从后向前，左边孩子比右边孩子大则多发一个或本身就比右边大的话，取原值
        for(int i=ratings.size()-1; i>0; i--){
            if(ratings[i-1] > ratings[i]) result[i-1] = max(result[i]+1, result[i-1]);
        }

        int sumCandy = 0;
        for(int i=0; i<result.size(); i++){
            sumCandy += result[i];
        }
        return sumCandy;
    }
};
// @lc code=end

