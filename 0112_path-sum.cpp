class Solution {
private:
    bool dfs(TreeNode* n, const int sum, int cur) {
        if (!n) return 0;
        if (!n->left && !n->right) return sum == cur + n->val;
        return dfs(n->left, sum, cur + n->val) || dfs(n->right, sum, cur + n->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return dfs(root, sum, 0);
    }
};
