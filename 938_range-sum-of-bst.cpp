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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (L <= f->val && f->val <= R) ans += f->val;
            if (f->left) q.push(f->left);
            if (f->right) q.push(f->right);
        }
        return ans;
    }
};
