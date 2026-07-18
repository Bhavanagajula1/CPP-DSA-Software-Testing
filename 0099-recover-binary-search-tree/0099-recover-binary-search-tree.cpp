class Solution {
public:
    void dfs(TreeNode* root, vector<TreeNode*> &v) {
        if (!root) return;

        dfs(root->left, v);
        v.push_back(root);
        dfs(root->right, v);
    }

    void recoverTree(TreeNode* root) {

        vector<TreeNode*> v;

        v.push_back(new TreeNode(INT_MIN));

        dfs(root, v);

        v.push_back(new TreeNode(INT_MAX));

        TreeNode *a = nullptr, *b = nullptr;

        for (int i = 1; i < v.size() - 1; i++) {

            if (v[i]->val > v[i + 1]->val) {

                if (a == nullptr) {
                    a = v[i];
                }

                b = v[i + 1];
            }
        }

        swap(a->val, b->val);
    }
};