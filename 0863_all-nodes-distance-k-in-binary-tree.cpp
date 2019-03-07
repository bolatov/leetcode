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
private:
    /**
     * Finds a path from root node to the target node.
     */
    vector<TreeNode*> dfs(TreeNode* root, TreeNode* target) {
        if (!root) return {};
        if (root == target) return {root};
        
        auto left = dfs(root->left, target);
        auto right = dfs(root->right, target);
        
        if (!left.empty()) {
            left.push_back(root);
            return left;
        } else if (!right.empty()) {
            right.push_back(root);
            return right;
        } else return {};
    }
    
    /**
     * Finds node's children that are at distance K.
     */
    vector<int> find(TreeNode* node, int K) {
        if (K < 0 || !node) return {};
        if (K == 0) return {node->val};
        vector<int> vi;
        queue<pair<TreeNode*, int>> q;
        q.push({node, 0});
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (f.second == K) {
                vi.push_back(f.first->val);
                continue;
            }
            if (f.first->left) q.push({f.first->left, f.second + 1});
            if (f.first->right) q.push({f.first->right, f.second + 1});
        }
        return vi;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> vi = find(target, K);
        
        // There is a path from root node to the target node.
        auto path = dfs(root, target);
        reverse(path.begin(), path.end());
        size_t n = path.size();
        for (size_t i = 0; i + 1 < n; i++) {
            // i-th parent node can have at most two children.
            // Get that node, that is not on the path from root to target.
            auto node = path[i]->left == path[i + 1] ? path[i]->right : path[i]->left;
            auto vj = find(node, K - (n - i));
            vi.insert(vi.end(), vj.begin(), vj.end());
            
            // Check if i-th parent node is at distance K.
            if (K == (n - 1 - i)) vi.push_back(path[i]->val);
        }
        
        return vi;
    }
};
