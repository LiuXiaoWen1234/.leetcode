/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> result;
    int curMaxCount = 0;
    int count = 0;
    TreeNode* pre = NULL;
    
    void traversal(TreeNode* root){
        if(root==NULL) return;

        //单层递归逻辑，中序遍历
        traversal(root->left);
        if(pre == NULL) count = 1;
        if(pre!=NULL && pre->val!=root->val) count = 1;
        if(pre!=NULL && pre->val==root->val) count++;
        
        pre = root;

        if(count == curMaxCount){
            result.push_back(root->val);
        }
        if(count > curMaxCount){
            curMaxCount = count;
            result.clear();
            result.push_back(root->val);
        }
        

        traversal(root->right);
        return;

    }


public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        curMaxCount = 0;
        result.clear();
        TreeNode* pre = NULL;

        traversal(root);
        return result;
        

    }
};
// @lc code=end

