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
private:
    bool dfs(TreeNode* root, TreeNode* p) {
        if (!root) return false;
        if (root == p) return true;
        return dfs(root->left, p) || dfs(root->right, p);
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (p == q) return p;
        if ((dfs(root->left, p) && dfs(root->right, q)) || (dfs(root->left, q) && dfs(root->right, p))) {
            return root;
        }
        
        auto left = lca(root->left, p, q);
        if (left) return left;
        return lca(root->right, p, q);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> vt;
        int maxDepth = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, maxDepth + 1});
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (f.second > maxDepth) {
                maxDepth = f.second;
                vector<TreeNode*> empty;
                vt = empty;
            }
            vt.push_back(f.first);
            if (f.first->left)  q.push({f.first->left, f.second + 1});
            if (f.first->right) q.push({f.first->right, f.second + 1});
        }
        return lca(root, vt.front(), vt.back());
    }
};
