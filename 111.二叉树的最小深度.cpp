/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        int  mindepth  = 0;
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);


        while(!que.empty()){
            mindepth++;
            int quesize = que.size();
            for(int i=0; i<quesize; i++){
                TreeNode* curnode = que.front();
                que.pop();
                
                if(curnode->left) que.push(curnode->left);
                if(curnode->right) que.push(curnode->right);
                if(!curnode->left && !curnode->right) return mindepth;
            }
        }
        return mindepth;
    }
};
// @lc code=end

