/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    vector<string> tempresult;
    bool huiwen(string str, int start, int end){
        while(start < end){
            if(str[start]!=str[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void backtracking(string s, int startIndex){
        if(startIndex >= s.size()){
            result.push_back(tempresult);
            return;
        }

        for(int i=startIndex; i<s.size(); i++){
            if(huiwen(s, startIndex, i)){
                
                string str = s.substr(startIndex, i-startIndex+1);
                tempresult.push_back(str);
            }else{
                continue;
            }

            backtracking(s, i+1);
            tempresult.pop_back();
        }
    }


public:
    vector<vector<string>> partition(string s) {
        result.clear();
        tempresult.clear();
        backtracking(s,0);
        return result;


    }
};
// @lc code=end

