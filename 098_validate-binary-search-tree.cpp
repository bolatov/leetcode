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
    bool isValid(TreeNode* root, long minValue, long maxValue) {
        if (!root) {
            return true;
        }
        return (minValue <= root->val && root->val <= maxValue) &&
                isValid(root->left, minValue, root->val - 1L) &&
                isValid(root->right, root->val + 1L, maxValue);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
