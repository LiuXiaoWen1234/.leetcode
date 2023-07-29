/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur==nullptr) return;
        traversal(cur->left, vec);//左子树
        vec.push_back(cur->val);//根节点
        traversal(cur->right, vec);//右子树
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;

    }
};
*/

class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;

     
        TreeNode* cur = root;
        while(cur!=NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;  //左
            }else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val); //中
                cur = cur ->right;
            }
        }
        return result;
    }
};
 @lc code=end

