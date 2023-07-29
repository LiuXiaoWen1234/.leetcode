/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
    int num = n;
    int sum = 0;
    unordered_set<int> sum_result;

    while(sum!=1){
        sum = 0;
        while(num!=0){
            sum += pow(num % 10,2);
            num = num/10;
        }

        if(sum_result.find(sum)!=sum_result.end()){
            return false;
        }else{
            sum_result.insert(sum);
        }
        num = sum;      
    }

    return true;

    }
};
// @lc code=end

