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

class Node {
public:
    int minNode, maxNode, sum;

    Node(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    Node helper(TreeNode* root) {

        // Empty tree is a BST
        if (root == nullptr)
            return Node(INT_MAX, INT_MIN, 0);

        Node left = helper(root->left);
        Node right = helper(root->right);

        // Check BST property
        if (left.maxNode < root->val && root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return Node(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // Not a BST
        return Node(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};