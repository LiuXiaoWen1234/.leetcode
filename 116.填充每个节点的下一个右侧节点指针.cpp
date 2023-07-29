/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //层次遍历，使用队列结构
        queue<Node*> que;
        if(root!=NULL) que.push(root);
        
        while(!que.empty()){
            Node* nodepre;
            Node* nodecur;
            int size = que.size();
            for(int i=0; i<size; i++){
                nodecur = que.front();
                que.pop();
                if(i==0){
                    nodepre = nodecur;
                }else{
                    nodepre->next = nodecur;
                    nodepre = nodepre->next;
                }
                if(nodecur->left) que.push(nodecur->left);//左子树先进队列
                if(nodecur->right) que.push(nodecur->right);
            }
            nodepre->next = NULL;
        }

        return root;
    }
};
// @lc code=end

