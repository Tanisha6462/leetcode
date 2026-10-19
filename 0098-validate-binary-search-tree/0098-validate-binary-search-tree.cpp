class Solution {
public:
    bool helper(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        bool left = helper(root->left, min, root->val);
        bool right = helper(root->right, root->val, max);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};