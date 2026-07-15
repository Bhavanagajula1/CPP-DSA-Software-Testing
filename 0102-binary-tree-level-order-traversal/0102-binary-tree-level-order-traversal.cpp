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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){return ans;}//fisrt ea root null anuko ans return 
        queue<TreeNode*>q;
        q.push(root);//first root push ayipodhi size=1,pop ayidhi level loki push
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left!=nullptr){q.push(node->left);}
                if(node->right!=nullptr){q.push(node->right);}
            }
            ans.push_back(level);
        }
        return ans;
    }
};