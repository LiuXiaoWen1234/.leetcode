/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
 /*
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right){
        if(left==NULL && right!=NULL) return false;
        else if(left!=NULL && right==NULL) return false;
        else if(left==NULL && right==NULL) return true;
        else if(left->val != right->val) return false;
        
        //左右节点都不为空，且节点数值相等，此时做递归
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool issame = outside && inside;
        return issame;
    }


    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return compare(root->left, root->right);
    }
};
*/


//使用迭代法，队列结构
class Solution{
public:
    bool isSymmetric(TreeNode* root){
        queue<TreeNode*> que;
        if(root==NULL) return true;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode* leftnode = que.front();
            que.pop();
            TreeNode* rightnode = que.front();
            que.pop();

            if(leftnode!=NULL && rightnode==NULL) return false;
            if(rightnode!=NULL && leftnode==NULL) return false;
            if(leftnode==NULL && rightnode==NULL) continue;
            if(rightnode->val!=leftnode->val) return false;

            que.push(leftnode->left);
            que.push(rightnode->right);
            que.push(leftnode->right);
            que.push(rightnode->left);

        }
        return true;
    }
};
// @lc code=end

