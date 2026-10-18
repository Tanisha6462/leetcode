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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }

        if(p == nullptr || q == nullptr ){
            return false;
        }

        if(p->val != q->val){
            return false;
        }
        return true && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        queue<TreeNode*>q;
        TreeNode* p = nullptr;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->val == subRoot->val){
                    p = front;
                    if(isSameTree(p,subRoot)){
                        return true;
                    }
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        } 
        return false;
    }
};