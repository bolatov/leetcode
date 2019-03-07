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
    void dfs(TreeNode* root, vector<int>& vt) {
        if (!root) return;
        dfs(root->left, vt);
        vt.push_back(root->val);
        dfs(root->right, vt);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> vt;
        dfs(root, vt);
        int diff = abs(vt[vt.size() - 1] - vt[0]);
        for (int i = 1; i < vt.size(); i++) {
            diff = min(diff, vt[i] - vt[i - 1]);
        }
        return diff;
    }
};
