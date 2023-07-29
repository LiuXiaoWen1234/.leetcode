/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            // i=2 j=1 dp[2] = 0+dp[1]*dp[0] = 1
            //     j=2 dp[2] = 1 + dp[0]*dp[1] = 2

            // i=3 j=1 dp[3] = 0+dp[2]*dp[0] = 2
            //     j=2 dp[3] = 2+dp[1]*dp[1] = 3
            //     j=3 dp[3] = 3+dp[0]*dp[2] = 5
            for(int j=1; j<=i; j++){ //第几个数作为根节点
                dp[i] = dp[i] + dp[i-j]*dp[j-1];  //左子树的树形+右子树的树形
            }
        }
        return dp[n];
    }
};
// @lc code=end

