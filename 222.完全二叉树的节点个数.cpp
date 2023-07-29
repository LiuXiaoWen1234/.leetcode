/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        //终止条件
        if(root==NULL) return 0;
        TreeNode* leftnode = root->left;
        TreeNode* rightnode = root->right;
        int leftdepth = 0;
        int rightdepth = 0;
        while(leftnode!=NULL){
            leftdepth++;
            leftnode = leftnode->left;
        }
        while(rightnode!=NULL){
            rightdepth++;
            rightnode = rightnode->right;
        }
        //若是满二叉树，则返回节点数量
        if(rightdepth == leftdepth) return (2<<leftdepth) - 1; //2<<1相当于2^2
        //若不是，则继续向左右子查找
        else return countNodes(root->left) + countNodes(root->right) + 1;

    }
};
// @lc code=end

