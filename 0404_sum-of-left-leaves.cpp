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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->left) {
                if (!p->left->left && !p->left->right) {
                    sum += p->left->val;
                } else {
                    q.push(p->left);
                }
            }
            if (p->right) {
                q.push(p->right);
            }
        }
        return sum;
    }
};
