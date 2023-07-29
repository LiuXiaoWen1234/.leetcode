/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        //层次遍历用队列
        vector<vector<int>> result;
        queue<Node*> que;
        if(root!=NULL) que.push(root);

        while(!que.empty()){
            int quesize = que.size();
            vector<int> vec;
            while(quesize--){
                Node* curnode = que.front();
                que.pop();
                vec.push_back(curnode->val);
                for(Node* chil:curnode->children){
                    if(chil!=nullptr) que.push(chil);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
// @lc code=end

