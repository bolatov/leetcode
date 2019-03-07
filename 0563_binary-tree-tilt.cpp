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
    int dfs(TreeNode* root, vector<int>& vi) {
        if (!root) return 0;
        int lSum = dfs(root->left, vi);
        int rSum = dfs(root->right, vi);
        vi[0] += abs(rSum - lSum);
        return lSum + rSum + root->val;
    }
    int findTilt(TreeNode* root) {
        vector<int> vi = {0};
        dfs(root, vi);
        return vi[0];
    }
};
