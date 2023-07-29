/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root==NULL) return result;

        TreeNode* cur;
        que.push(root);
        while(!que.empty()){
            int quesize = que.size();
            vector<int> temp;
            while(quesize--){
                cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push_back(temp);

        }

        reverse(result.begin(), result.end());
        return result;

    }
};
// @lc code=end

