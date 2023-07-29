/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode* curnode, vector<int>& vec, vector<string>& result){
        vec.push_back(curnode->val);

        //确定终止条件：叶子节点
        if(curnode->left==NULL && curnode->right==NULL){
            string str;
            for(int i=0; i<vec.size()-1; i++){
                str += to_string(vec[i]);
                str +="->";
            }
            str += to_string(vec[vec.size()-1]);
            result.push_back(str);
        }
        //确定单层递归逻辑
        if(curnode->left){
            traversal(curnode->left, vec, result); //递归进左节点
            vec.pop_back();//递归完回溯
        }
        if(curnode->right){
            traversal(curnode->right, vec, result);
            vec.pop_back();//回溯
        }
    }



    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> vec;
        vector<string> result;
        if(root==NULL) return result;
        traversal(root, vec, result);
        return result;

    }
};
// @lc code=end

