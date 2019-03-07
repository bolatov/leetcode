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
    bool equals(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t || s->val != t->val) return false;
        return equals(s->left, t->left) && 
            equals(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        queue<TreeNode*> q, qt;
        q.push(s);
        while (!q.empty()) {
            TreeNode* tn = q.front();
            q.pop();
            if (tn->val == t->val) qt.push(tn);
            if (tn->left) q.push(tn->left);
            if (tn->right) q.push(tn->right);
        }
        while (!qt.empty()) {
            TreeNode* tn = qt.front();
            qt.pop();
            if (equals(tn, t)) return true;
        }
        return false;
    }
};
