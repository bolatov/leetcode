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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        int row = 0, maxValue = root->val;
        queue<pair<TreeNode*, int>> q;
        q.push({root, row});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front.second > row) {
                v.push_back(maxValue);
                row = front.second;
                maxValue = front.first->val;
            } else {
                maxValue = max(maxValue, front.first->val);
            }
            
            if (front.first->left) {
                q.push({front.first->left, front.second + 1});
            }
            if (front.first->right) {
                q.push({front.first->right, front.second + 1});
            }
        }
        
        if (v.size() < row + 1) v.push_back(maxValue);
        
        return v;
    }
};
