/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        //层次遍历使用队列结构
        queue<TreeNode*> que;
        if(root==NULL) return 0;
        que.push(root);
        TreeNode* cur;
        int result;
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                cur = que.front();
                que.pop();
                //最左边的叶子节点
                if(i==0 && cur->left==NULL && cur->right==NULL)
                    result = cur->val;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};
// @lc code=end

