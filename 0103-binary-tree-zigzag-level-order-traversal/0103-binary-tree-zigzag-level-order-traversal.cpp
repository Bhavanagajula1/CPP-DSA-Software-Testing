class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == nullptr)
            return ans;

        bool left2right = true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                int idx = left2right ? i : size - 1 - i;

                level[idx] = node->val;

                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);
            }

            left2right = !left2right;

            ans.push_back(level);
        }

        return ans;
    }
};