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
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            if (!n->left && !n->right) {
                sum += n->val;
            } else {
                int v = n->val * 10;
                if (n->left) {
                    n->left->val += v;
                    q.push(n->left);
                }
                if (n->right) {
                    n->right->val += v;
                    q.push(n->right);
                }
            }
        }
        return sum;
    }
};