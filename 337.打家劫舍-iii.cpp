/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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

    vector<int> traversal(TreeNode* root)
    {
        vector<int> ve(2, 0); //保存当前节点盗取最高金额，及下一节点盗取最高金额
        vector<int> ve2(2, 0);
        vector<int> result(2, 0);
        if(root->left == nullptr && root->right == nullptr){
            result[0] = root->val;
            result[1] = 0;
        }else if(root->left != nullptr && root->right == nullptr){
            ve = traversal(root->left);
            result[0] = max(ve[0], ve[1]+root->val);
            result[1] = ve[0];
        }else if(root->left == nullptr && root->right != nullptr){
            ve = traversal(root->right);
            result[0] = max(ve[0], ve[1]+root->val);
            result[1] = ve[0];
        }else{
            ve = traversal(root->left);
            ve2 = traversal(root->right);
            result[0] = max(ve[0]+ve2[0], ve[1]+ve2[1]+root->val);
            result[1] = ve[0]+ve2[0];
        }
        return result;
    }


    int rob(TreeNode* root) {
        vector<int> result(2, 0);
        if(root->left == nullptr && root->right == nullptr) return root->val;
        result = traversal(root);
        return result[0];
    }
};
// @lc code=end

