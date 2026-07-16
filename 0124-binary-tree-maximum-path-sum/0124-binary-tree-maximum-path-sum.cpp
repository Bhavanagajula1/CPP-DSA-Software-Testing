/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int findPath(TreeNode* root, int &maxi) {

        // Base case
        if (root == nullptr) {
            return 0;
        }

        // Find maximum path sum from left and right subtree
        int leftSum = max(0, findPath(root->left, maxi));
        int rightSum = max(0, findPath(root->right, maxi));

        // Update the maximum path sum
        maxi = max(maxi, leftSum + rightSum + root->val);

        // Return the maximum single path to parent
        return max(leftSum, rightSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        findPath(root, maxi);

        return maxi;
    }
};