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
    int cnt ;
    pair<int , int> solve(TreeNode* root){
        if(root == nullptr){
            return {0,0};
        }
        pair<int , int> left = solve(root->left);
        pair<int , int> right = solve(root->right);

        int sum = left.first + right.first + root->val;
        int node_cnt = left.second + right.second + 1;

        if(sum/node_cnt == root->val){
            cnt++;
        }

        return {sum , node_cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        cnt = 0;
        solve(root);
        return cnt;
    }
};