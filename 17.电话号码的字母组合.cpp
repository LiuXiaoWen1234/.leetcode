/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
    string tempResult;
    const string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };

    void backtracking(string digits, int index){
        if(index==digits.size()){
            result.push_back(tempResult);
            return;
        }

        int digit = digits[index] - '0';
        string str = letterMap[digit];
        for(int i=0; i<str.size(); i++){
            tempResult.push_back(str[i]);
            backtracking(digits, index+1);
            tempResult.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        result.clear();
        tempResult="";
        if(digits.size()==0) return result;

        backtracking(digits, 0);
        return result;

    }
};
// @lc code=end

