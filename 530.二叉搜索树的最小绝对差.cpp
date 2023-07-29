/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
private:
    int minAbs = INT_MAX;
    TreeNode* pre = NULL;
    void traversal(TreeNode* cur){
        //结束条件
        if(cur==NULL) return;

        //单层递归逻辑,中序遍历
        traversal(cur->left);
        if(pre!=NULL && abs(pre->val - cur->val)<minAbs) minAbs=abs(pre->val - cur->val);
        pre = cur;
        traversal(cur->right); 

    }

public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minAbs;

    }
};
// @lc code=end

