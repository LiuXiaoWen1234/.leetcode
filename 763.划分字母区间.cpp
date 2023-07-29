/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int maxlocation[26] = {0};
        for(int i=s.size()-1; i>=0; i--){
            maxlocation[s[i]-'a'] = max(maxlocation[s[i]-'a'],i);
        }
        // for(int i=0; i<s.size(); i++){
        //     cout<<maxlocation[i]<<endl;
        // }


        int start = 0;
        int end = 0;
        vector<int> result;
        while(start <= s.size()-1){
            end = maxlocation[s[start]-'a'];
            for(int j=start; j<=end; j++){
                end = max(end, maxlocation[s[j]-'a']);
            }
            //cout<<"start: "<<start<<"  end: "<<end<<endl; 
            result.push_back(end-start +1);
            start = end+1; 
             
        }
        return result;
    }
};
// @lc code=end

