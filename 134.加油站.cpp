/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cursum = 0, totalsum = 0;
        int startPos = 0;
        for(int i=0; i<gas.size(); i++){
            int res = gas[i] - cost[i];
            totalsum += res;
            cursum += res;
            if(cursum <0){
                startPos = i+1;
                cursum = 0;
            }
        }

        if(totalsum < 0) return -1;
        return startPos;
    }
};
// @lc code=end

