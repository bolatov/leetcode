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
    int findBottomLeftValue(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val;
        }
        queue<pair<TreeNode*, int>> q;
        int level = 0, value = root->val;
        q.push({root, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int nextLevel = p.second + 1;
            auto left = p.first->left;
            auto right = p.first->right;
            if (left) {
                if (nextLevel > level) {
                    level = nextLevel;
                    value = left->val;
                }
                q.push({left, nextLevel});
            }
            
            if (right) {
                if (nextLevel > level) {
                    level = nextLevel;
                    value = right->val;
                }
                q.push({right, nextLevel});
            }
        }
        return value;
    }
};
