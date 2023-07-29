/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> result;

    void traversal(TreeNode* cur, vector<int> &vec, int count){
        if(cur==NULL) return;
        vec.push_back(cur->val);
        count -= cur->val;
        if(!cur->left && !cur->right && count==0)
            result.push_back(vec);
        if(!cur->left && !cur->right && count!=0)
            return;
        
        if(cur->left){
            traversal(cur->left,vec,count);
            vec.pop_back();
        }
        if(cur->right){
            traversal(cur->right,vec,count);
            vec.pop_back();
        }
        
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        if(root==NULL) return result;
        vector<int> vec;
        traversal(root, vec, targetSum);
        return result;

    }
};
// @lc code=end

