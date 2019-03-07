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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vvi;
        if (!root) return vvi;
        
        // Traverse the tree with BFS
        queue<pair<TreeNode*, vector<int>>> q;
        vector<int> _v;
        q.push({root, _v});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* tn = p.first;
            vector<int> vi = p.second;
            vi.push_back(tn->val);
            
            // Leaf node is reached
            if (!tn->right && !tn->left) {
                int sm = 0;
                for (int i : vi) sm += i;
                
                if (sm == sum) vvi.push_back(vi);
            }
            if (tn->left) {
                vector<int> v(vi);
                q.push({tn->left, v});
            }
            if (tn->right) {
                vector<int> v(vi);
                q.push({tn->right, v});
            }
        }
        return vvi;
    }
};
