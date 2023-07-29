/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void traversal(TreeNode* cur, vector<int>&vec){
        if(cur==nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }


    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
        

    }
};
*/

class Solution{
    public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if(root==NULL) return result;

        st.push(root);
        TreeNode* curNode;
        while(!st.empty()){
            curNode = st.top(); //取出头节点
            st.pop();
            result.push_back(curNode->val); //将节点数值加入到数组中
            if(curNode->right!=nullptr) st.push(curNode->right);
            if(curNode->left!=nullptr) st.push(curNode->left);
        }

        return result; 
    }
};
// @lc code=end

