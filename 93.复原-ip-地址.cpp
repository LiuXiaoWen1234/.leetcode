/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
private:
    vector<string> result;

    bool isValid(const string&s, int start, int end){
        if(start > end) return false;
        if(s[start]=='0' && start!=end) return false; //“01”不是有效IP字段,"0"is
        int num = 0;
        for(int i=start; i<=end; i++){
            if(s[i]>'9' || s[i]<'0') return false; //非法字符
            num = num*10 + (s[i]-'0');
            if(num>255) return false;
        }
        return true;

    }

    void backtracking(string& s, int startIndex, int pointNum){
        //终止条件
        if (pointNum == 3) { // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }     

        //单层回溯逻辑
        for (int i=startIndex; i<s.size()&&i<startIndex+3; i++){
            //从startIndex截取子串
            if(isValid(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.'); //i的后面假逗号
                
                backtracking(s, i+2, pointNum+1);
                
                s.erase(s.begin()+i+1);

            }else break;
        }
    }


public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.size()<4 ||s.size()>12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end

