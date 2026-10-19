/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        TreeNode* left = nullptr;
        if(root->left){
            left = lowestCommonAncestor(root->left,p,q);
        }
        TreeNode* right = nullptr;
        if(root->right){
            right = lowestCommonAncestor(root->right,p,q);
        }
        
        if(left != nullptr && right != nullptr){
            return root;
        }
        if(left == nullptr){
            return right;
        }
        return left;
    }
};