class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vvi;
        if (!root) return vvi;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (vvi.size() <= t.second) vvi.push_back(vector<int>());
            vvi[vvi.size()-1].push_back(t.first->val);
            if (t.first->left) q.push({t.first->left, t.second+1});
            if (t.first->right) q.push({t.first->right, t.second+1});
        }
        reverse(vvi.begin(), vvi.end());
        return vvi;
    }
};
