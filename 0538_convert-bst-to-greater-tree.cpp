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
    void dfs(TreeNode* root, vector<TreeNode*>& vt) {
        if (!root) return;
        dfs(root->right, vt);
        vt.push_back(root);
        dfs(root->left, vt);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> vt;
        dfs(root, vt);
        for (int i = 1; i < vt.size(); i++) {
            vt[i]->val += vt[i - 1]->val;
        }
        return root;
    }
};
