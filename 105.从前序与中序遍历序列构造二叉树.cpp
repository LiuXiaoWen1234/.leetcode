/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //条件返回
        if(preorder.size()==0){
            return NULL;
        }

        //在前序遍历中截取根节点
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        //在中序遍历中找打根节点的位置
        int rootPos;
        for(rootPos=0; rootPos<inorder.size(); rootPos++){
            if(inorder[rootPos] == rootValue)
                break;
        }

        //中序遍历截取左子树和右子树，左闭右开原则
        vector<int> inLeftTree (inorder.begin(), inorder.begin()+rootPos);
        vector<int> inRightTree(inorder.begin()+rootPos+1, inorder.end());

        //先序遍历找到左子树和右子树
        vector<int> preLeftTree(preorder.begin()+1, preorder.begin()+1+rootPos);
        vector<int> preRightTree(preorder.begin()+rootPos + 1, preorder.end());

        //递归左子树和右子树
        root->left = buildTree(preLeftTree, inLeftTree);
        root->right = buildTree(preRightTree, inRightTree);

        return root;

    }
};
// @lc code=end

