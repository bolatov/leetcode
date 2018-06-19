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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {return {};}
        vector<int> vi;
        auto vl = postorderTraversal(root->left);
        auto vr = postorderTraversal(root->right);
        vi.insert(vi.end(), vl.begin(), vl.end());
        vi.insert(vi.end(), vr.begin(), vr.end());
        vi.push_back(root->val);
        return vi;
    }
};
