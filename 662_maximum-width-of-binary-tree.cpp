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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        int minOrder = INT_MAX, maxOrder = INT_MIN;
        int level = 0;
        // TreeNode*, order, level
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {1, level}});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int o = p.second.first;
            int l = p.second.second;
            
            if (l > level) {
                minOrder = maxOrder = o;
                level = l;
            } else {
                minOrder = min(minOrder, o);
                maxOrder = max(maxOrder, o);
            }
            
            ans = max(maxOrder - minOrder + 1, ans);
            
            if (node->left) {
                q.push({node->left, {o * 2 - 1, l + 1}});
            }
            if (node->right) {
                q.push({node->right, {o * 2, l + 1}});
            }
        }
        return ans;
    }
};
