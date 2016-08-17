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
    int dfs(TreeNode *n, int d) {
        if (!n->left && !n->right) {
            return d;
        }

        if (n->left && n->right) {
            return min(dfs(n->left, d + 1), dfs(n->right, d + 1));
        } else if (n->left) {
            return dfs(n->left, d + 1);
        } else {
            return dfs(n->right, d + 1);
        }
    }

  public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        return dfs(root, 1);
    }
};