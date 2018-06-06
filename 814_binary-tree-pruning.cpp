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
    bool hasOne(TreeNode* root) {
        if (!root) return false;
        if (root->val == 1) return true;
        return hasOne(root->left) || hasOne(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto tn = q.front();
            q.pop();
            if (!hasOne(tn->left)) tn->left = NULL;
            if (!hasOne(tn->right)) tn->right = NULL;
            
            if (tn->left) q.push(tn->left);
            if (tn->right) q.push(tn->right);
        }
        return root;
    }
};
