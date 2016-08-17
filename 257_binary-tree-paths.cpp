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
    string toString(int t) {
        stringstream ss;
        ss << t;
        return ss.str();
    }
    void dfs(TreeNode *n, vector<string> &v, string s) {
        s += toString(n->val);
        if (!n->left && !n->right) {
            v.push_back(s);
            return;
        }
        s += "->";
        if (n->left)
            dfs(n->left, v, s);
        if (n->right)
            dfs(n->right, v, s);
    }

  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> v;
        if (!root)
            return v;
        dfs(root, v, "");
        return v;
    }
};