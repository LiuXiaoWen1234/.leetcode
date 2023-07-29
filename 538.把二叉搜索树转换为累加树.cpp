/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    
    TreeNode* Traversal(TreeNode* root, TreeNode* pre) {
        if(root==NULL) return root;

        //右 中 左顺序遍历等于从大到小的数组遍历
        if(root->right) pre = Traversal(root->right, pre);

        if(pre==NULL && !root->right){
            pre = root;
        }else if(pre) {
            root->val = pre->val + root->val;
            pre = root;
        }

        if(root->left) pre = Traversal(root->left, pre);
        return pre;
        

    }

public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* pre = NULL;
        pre = Traversal(root, pre);
        return root;      

    }
};
// @lc code=end

