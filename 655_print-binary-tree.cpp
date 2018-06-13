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
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        int height = 1;
        q.push({root, height});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            height = max(height, p.second);
            if (p.first->left)  { q.push({p.first->left, p.second + 1}); }
            if (p.first->right) { q.push({p.first->right, p.second + 1}); }
        }
        return height;
    }
    void dfs(TreeNode* root, vector<vector<string>>& vvs, int level, int pos) {
        vvs[level][pos] = to_string(root->val);
        int w2 = vvs[0].size();
        int dd = 1 << (level + 2);
        int div = w2 / dd + 1;
        if (level + 1 == vvs.size()) return;
        // printf("for %d [%d][%d] l=[%d][%d] r=[%d][%d] w2=%d dd=%d\n", root->val, level, pos, level + 1, pos - div, level + 1, pos + div, w2, dd);
        if (root->left)  { dfs(root->left, vvs, level + 1, pos - div); }
        if (root->right) { dfs(root->right, vvs, level + 1, pos + div); }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int w = (1 << h) - 1;
        vector<vector<string>> vvs(h, vector<string>(w, ""));
        dfs(root, vvs, 0, w / 2);
        return vvs;
    }
};
