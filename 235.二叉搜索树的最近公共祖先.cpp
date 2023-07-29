/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;

        if(q->val < root->val && p->val < root->val){
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if(left) return left;

        }

        if( p->val > root->val &&  q->val > root->val){
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(right!=NULL) return right;
        }
        

        return root;
    }
};
// @lc code=end

