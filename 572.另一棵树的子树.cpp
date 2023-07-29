/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    //判断两棵子树是否相等
    bool isSameSubTree(TreeNode* left, TreeNode* right){
        if(left==NULL && right!=NULL) return false;
        else if(left!=NULL && right==NULL) return false;
        else if(left==NULL && right==NULL) return true;
        else if(left->val != right->val) return false;
        else return isSameSubTree(left->left,right->left) && isSameSubTree(left->right, right->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        else if(root==NULL && subRoot!=NULL) return false;
        else if(root!=NULL && subRoot==NULL) return false;

        //定义个队列遍历节点
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* curnode;
        while(!que.empty()){
            curnode = que.front();
            que.pop();
            if(isSameSubTree(curnode, subRoot)) return true;
            //若不相等，则在队列中加入左右孩子
            if(curnode->left) que.push(curnode->left);
            if(curnode->right) que.push(curnode->right);

        }
        
        return false;
    }
};
// @lc code=end

