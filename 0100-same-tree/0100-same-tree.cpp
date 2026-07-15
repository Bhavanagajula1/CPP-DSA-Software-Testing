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
       if(p==nullptr && q==nullptr)
        return true;
        //p side q side 2 same vunte adhi same kabati so 0 vunte same ani using and means comapring p=0,q=0 true then only true.if p=0;q=1 then false. so automatic false ayina manam rayali..
        if(p==nullptr || q==nullptr)
            return false;
            //using or p=0;q=1 aithe false ani.ipuduu root nodes ayipoyay so next right and left.
        if(p->val!=q->val)
        return false;
        //vvariables ante values ipudu daka just design ipudu comapring values.
        return isSameTree(p->right,q->right)&&
            isSameTree(p->left,q->left);
    }
};