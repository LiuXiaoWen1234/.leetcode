/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //状态说明：0无覆盖，1放置摄像头，2有覆盖
private:
    int result;
    int traversal(TreeNode* cur){
        if(cur==NULL) return 2;

        int left = traversal(cur->left);
        int right = traversal(cur->right);

        //左右孩子都有覆盖
        if(left==2 && right==2) return 0;
        //有一个孩子没被覆盖
        if(left==0 || right==0){
            result++;
            return 1;
        }
        if(left==1 || right==1) return 2;
        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if(traversal(root)==0){
            result++;
        }
        return result;
    }
};
// @lc code=end

