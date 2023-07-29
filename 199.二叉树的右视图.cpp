/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> resultFinal;
        queue<TreeNode*> que;
        if(root==NULL) return resultFinal;

        TreeNode* cur;
        que.push(root);
        while(!que.empty()){
            int quesize = que.size();
            int flag = que.size();
            vector<int> temp;
            while(quesize--){
                cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            resultFinal.push_back(temp[flag-1]);

        }

        return resultFinal;
    }
};
// @lc code=end

