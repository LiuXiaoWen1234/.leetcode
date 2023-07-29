/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
public:
    long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        //确定结束条件
        if(root==NULL) return true;

        //确定单层逻辑
        bool left = isValidBST(root->left);

        if(maxVal < root->val) maxVal=root->val;
        else return false;

        bool right = isValidBST(root->right);

        return left&&right;
    }
};
// @lc code=end

