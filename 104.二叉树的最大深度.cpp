/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth=0;
        //使用队列结果层次遍历二叉树
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        TreeNode* curnode;

        while(!que.empty()){
            depth++;
            int quesize = que.size();
            while(quesize--){
                curnode = que.front();
                que.pop();
                if(curnode->left) que.push(curnode->left);
                if(curnode->right) que.push(curnode->right);
            }
        }
        return depth;

    }
};
*/

class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int depth = max(leftDepth, rightDepth) + 1;
        return depth;
    }
};
// @lc code=end

