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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        auto left = increasingBST(root->left);
        root->left = NULL;
        root->right = increasingBST(root->right);
        if (left) {
            auto node = left;
            while (node->right) {
                node = node->right;
            }
            node->right = root;
            return left;
        }
        return root;
    }
};
