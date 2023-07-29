/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       unordered_map<int, int> haveMoney; //记录当前的钱
       for(int i=0; i<bills.size(); i++){
            if(bills[i]==5) haveMoney[5]++;
            else if(bills[i]==10){
                if(haveMoney[5]){
                    haveMoney[5]--; //付一张五块
                    haveMoney[10]++; //收一张十块
                }else{
                    return false;
                }      
            }else if(bills[i]==20){
                if(haveMoney[10]&&haveMoney[5]){
                    haveMoney[10]--;
                    haveMoney[5]--;
                    haveMoney[20]++;
                }else if(haveMoney[5]>=3){
                    haveMoney[5] -=3;
                    haveMoney[20]++;
                }else{
                    return false;
                }
            }
       } 
        return true;
    }
};
// @lc code=end

