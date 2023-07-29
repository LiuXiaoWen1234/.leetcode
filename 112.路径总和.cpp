/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    //深度遍历-先序
    bool traversal(TreeNode* curnode, int count){
        if(curnode == NULL) return 0;
        count -= curnode->val;
        if(!curnode->left && !curnode->right && count==0) return true;
        if(!curnode->left &&!curnode->right && count!=0) return false;


        bool leftpath = traversal(curnode->left, count);
        bool rightpath = traversal(curnode->right, count);
        return leftpath||rightpath;


        
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return traversal(root, targetSum);

    }
};
// @lc code=end

