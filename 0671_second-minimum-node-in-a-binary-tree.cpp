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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) {
            return -1;
        }
        
        int head = root->val;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t->val != head) v.push_back(t->val);
            if (t->left) {
                q.push(t->left);
                q.push(t->right);
            }
        }
        sort(v.begin(), v.end());
        return v.empty() ? -1 : v[0];
    }
};
