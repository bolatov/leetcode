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
    int depth(TreeNode *n) {
        if (!n)
            return 0;
        return max(depth(n->left), depth(n->right)) + 1;
    }

  public:
    bool isBalanced(TreeNode *root) {
        // Tree is balanced when it is NULL or if it is a leaf.
        if (!root || (!root->left && !root->right))
            return true;

        // Check max depths difference of left and right children.
        if (abs(depth(root->left) - depth(root->right)) > 1)
            return false;

        // Check whether the subtrees are balanced.
        return isBalanced(root->left) && isBalanced(root->right);
    }
};