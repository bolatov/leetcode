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
    /**
     * rightSideView traverses a graph in a BFS manner.
     * On each level the right most element's value is added
     * to the final answer.
     */
    vector<int> rightSideView(TreeNode *root) {
        vector<int> v;

        // Pair consists of a TreeNode* and a depth of the node
        queue<pair<TreeNode *, int>> q;
        if (root) {
            q.push({root, 1});
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (v.size() < p.second) {
                // this value is the first on the current depth
                v.push_back(p.first->val);
            } else {
                // this is not the first value on this depth,
                // update the result
                v[v.size() - 1] = p.first->val;
            }

            // Add current nodes' children if they exist
            if (p.first->left) {
                q.push({p.first->left, p.second + 1});
            }
            if (p.first->right) {
                q.push({p.first->right, p.second + 1});
            }
        }
        return v;
    }
};