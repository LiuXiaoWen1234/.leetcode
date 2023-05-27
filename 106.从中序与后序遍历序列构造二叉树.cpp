/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return NULL;
        }

        int rootValue = postorder[postorder.size()-1];//后序遍历的最后一个元素是根节点

        //前序遍历中找到根节点的位置
        int inorderPos;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == rootValue){
                inorderPos = i;
                break;
            }
        }

        //定一个根节点，并保存地址
        TreeNode* root = new TreeNode(rootValue);

        //先在前序遍历中截出左子树和右子树,左闭右开
        vector<int> inleftTree (inorder.begin(), inorder.begin()+inorderPos);
        vector<int> inRightTree (inorder.begin()+inorderPos+1, inorder.end());

        //在后续遍历中截出左子树和右子树
        vector<int> postLeftTree (postorder.begin(), postorder.begin()+inorderPos);
        vector<int> postRightTree (postorder.begin()+inorderPos, postorder.end()-1);

        //递归处理左区间和右区间
        root->left = buildTree(inleftTree, postLeftTree);
        root->right = buildTree(inRightTree, postRightTree);

        return root;

    }
};
// @lc code=end

