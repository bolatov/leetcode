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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        set<int> si;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            si.insert(f->val);
            if (f->left) q.push(f->left);
            if (f->right) q.push(f->right);
        }
        for (int i : si) {
            if (k - i != i && si.find(k - i) != si.end()) return true;
        }
        return false;
    }
};
