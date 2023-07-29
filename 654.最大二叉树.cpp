/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //确定返回条件
        if(nums.size() == 0) return NULL;

        //确定单层递归逻辑
        int maxNum = INT_MIN;
        int maxNumIndex = -1;
        for(int i=0; i<nums.size();++i){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                maxNumIndex = i;
            }
        }
        //定义根节点
        TreeNode* root = new TreeNode(maxNum);
        //左子树,左开右闭
        vector<int> leftTree (nums.begin(), nums.begin()+maxNumIndex);
        vector<int> rightTree (nums.begin()+maxNumIndex+1, nums.end());
        //递归左右子树
        root->left = constructMaximumBinaryTree(leftTree);
        root->right = constructMaximumBinaryTree(rightTree);
        return root;



    }
};
// @lc code=end

