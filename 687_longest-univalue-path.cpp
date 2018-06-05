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
    int check(TreeNode* root, int val) {
        if (!root || root->val != val) return 0;
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* tn = p.first;
            int d = p.second;
            res = max(res, d);
            if (tn->left && tn->left->val == val) q.push({tn->left, d + 1});
            if (tn->right && tn->right->val == val) q.push({tn->right, d + 1});
        }
        
        return res;    
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            auto tn = q.front();
            q.pop();
            ans = max(ans, check(tn->left, tn->val) + check(tn->right, tn->val));
            
            if (tn->left) q.push(tn->left);
            if (tn->right) q.push(tn->right);
        }
        return ans;
    }
};
