/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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

 //递归法
 /*
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;

    }
};
*/


//迭代法要用到栈（PS层次遍历使用队列）
class Solution{
public:
    TreeNode* invertTree(TreeNode* root){
        stack<TreeNode*> sta;
        if(root!=NULL) sta.push(root);
        
        while(!sta.empty()){
            TreeNode* curnode = sta.top();
            sta.pop();
            swap(curnode->left, curnode->right);
            if(curnode->right) sta.push(curnode->right);
            if(curnode->left) sta.push(curnode->left);
        }
        return root;
    }
};

// @lc code=end

