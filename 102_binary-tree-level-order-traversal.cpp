class Solution {
public:
    /*
     * Traverse a binary tree in a BFS manner
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vvi;
        if (!root) return vvi;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto e = q.front();
            q.pop();
            if (vvi.size() <= e.second) {
                vector<int> vi;
                vvi.push_back(vi);
            }
            vvi[vvi.size()-1].push_back(e.first->val);
            if (e.first->left) q.push({e.first->left, e.second+1});
            if (e.first->right) q.push({e.first->right, e.second+1});
        }
        return vvi;
    }
};
