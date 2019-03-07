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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {return {};}
        vector<vector<int>> vvi;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            if (vvi.size() < p.second) {
                vector<int> vi;
                vvi.push_back(vi);
            }
            
            vvi[p.second - 1].push_back(p.first->val);
            if (p.first->left) q.push({p.first->left, p.second + 1});
            if (p.first->right) q.push({p.first->right, p.second + 1});
        }
        for (int i = 1; i < vvi.size(); i += 2) reverse(vvi[i].begin(), vvi[i].end());
        return vvi;
    }
};
