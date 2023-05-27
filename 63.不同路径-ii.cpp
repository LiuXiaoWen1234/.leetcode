/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==1 && n==1) return obstacleGrid[0][0]==0?1:0;

        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0]= obstacleGrid[0][0]==0?1:-1;
        for(int i=1; i<n; i++){
            if(obstacleGrid[0][i]==1) {
                dp[0][i]  = -1;
            }else{
                dp[0][i]=dp[0][i-1];
            }
        }
        for(int i=1; i<m; i++){
            if(obstacleGrid[i][0]==1){
                dp[i][0] = -1;
            }else{
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1 || (dp[i-1][j]==-1 && dp[i][j-1]==-1)){
                    dp[i][j]==-1;
                    continue;
                } 
                if(dp[i-1][j]==-1 && dp[i][j-1]!=-1) dp[i][j] = dp[i][j-1];
                else if(dp[i-1][j]!=-1 && dp[i][j-1]==-1) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        } 
        return dp[m-1][n-1]<0? 0:dp[m-1][n-1];
    }
};
// @lc code=end

