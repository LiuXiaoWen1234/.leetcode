/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        } 
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        } 

        if(root->val == key){
            if(!root->left && !root->right) return NULL;
            if(!root->left && root->right) return root->right;
            if(root->left && !root->right) return root->left;
            TreeNode* temp = root->right;
            while(temp->left) temp = temp->left;
            temp->left = root->left;
            return root->right;
        }

        return NULL;
    }
};
// @lc code=end

