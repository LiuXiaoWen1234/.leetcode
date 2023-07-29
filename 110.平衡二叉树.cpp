/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    //返回该节点的高度，若是-1则表示非平衡二叉树
    int balance(TreeNode* node){
        //终止条件
        if(node==NULL) return 0;
        int leftHeight = balance(node->left);
        int rightHeight = balance(node->right);
        if(leftHeight==-1 || rightHeight==-1) return -1;
        else if(abs(leftHeight - rightHeight)>1) return -1;
        else return max(leftHeight, rightHeight) + 1;

    }

    bool isBalanced(TreeNode* root) {
        int result = balance(root);

        return result==-1?false:true;

    }
};
// @lc code=end

