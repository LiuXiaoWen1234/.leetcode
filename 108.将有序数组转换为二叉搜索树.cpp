/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    //左闭右开
    TreeNode* traversal(vector<int>& nums, int left, int right){
        if(left >= right) return NULL;

        TreeNode* curnode = new TreeNode();
        // if(left = right){
        //     curnode->val = nums[left];
        // }

        if(left<right) {
            int medium = (left + right)/2;
            curnode->val = nums[medium];
            curnode->left = traversal(nums, left, medium);
            curnode->right = traversal(nums, medium+1, right);
        }

        return curnode;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size());
        return root;

    }
};
// @lc code=end

