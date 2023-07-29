/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root==NULL) return result;
        que.push(root);
        int queuesize = 1;

        TreeNode* cur;
        while(!que.empty()){
            vector<int> temp;
            while(queuesize--){
                cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push_back(temp);
            queuesize = que.size();
        }
        return result;
    }
};
// @lc code=end

