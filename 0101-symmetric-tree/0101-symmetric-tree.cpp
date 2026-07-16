class Solution {
public:
    bool helper(TreeNode* root1, TreeNode* root2) {

        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }

        return (root1->val == root2->val) &&
               helper(root1->left, root2->right) &&
               helper(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return helper(root->left, root->right);
    }
};