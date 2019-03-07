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
    void dfs(TreeNode* root, vector<int>& vi, const int sum) {
        if (!root) return;
        if (sum - root->val == 0) vi[0]++;
        dfs(root->left, vi, sum - root->val);
        dfs(root->right, vi, sum - root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        vector<int> vi = {0};
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tn = q.front();
            q.pop();
            dfs(tn, vi, sum);
            if (tn->left) q.push(tn->left);
            if (tn->right) q.push(tn->right);
        }
        
        return vi[0];
    }
};
