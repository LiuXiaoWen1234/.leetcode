/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
private:
    vector<string> path;

    static bool cmp(vector<string>& vs1, vector<string>& vs2){
        if(vs1[0] == vs2[0]) return vs1[1] < vs2[1];
        else return vs1[0] < vs2[0];
    }

    bool backtracking(vector<vector<string>>& tickets, vector<bool>& used, string startAirport){
        if(path.size() == tickets.size()+1){
            return true;
        }

        for(int i=0; i<tickets.size(); i++){
            if(used[i]==true) continue;
            if(tickets[i][0] != startAirport) continue;

            path.push_back(tickets[i][1]);
            used[i] = true;
            if(backtracking(tickets, used, tickets[i][1])) return true;
            used[i] = false;
            path.pop_back();
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), cmp);
        path.clear();
        path.push_back("JFK");
        vector<bool> used(tickets.size(), false);
        backtracking(tickets, used, "JFK");

        return path;
    }
};
// @lc code=end

