/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        //遍历饼干
        int result = 0;
        vector<bool> used(g.size(), false); //记录孩子是否已经被分到
        for(int i=s.size()-1; i>=0; i--){
            // traversal child
            for(int j=g.size()-1; j>=0; j--){
                if(s[i]>=g[j] && used[j]==false) {
                    result++;
                    used[j]=true; 
                    break; //跳出循环，进行下一个小饼干判断
                }
            }
        }
        return result;
    }   
};
// @lc code=end

