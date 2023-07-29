/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        if(val > root->val){
            TreeNode* result = insertIntoBST(root->right, val);
            root->right = result;
        }else if(val < root->val){
            TreeNode* result = insertIntoBST(root->left, val);
            root->left = result;
        }
        return root;
    }
};
// @lc code=end

