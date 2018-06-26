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
    int cnt = 0;
    int kthValue = -1;
    void inorder(TreeNode* root, const int k) {
        if (!root) return;
        inorder(root->left, k);
        cnt++;
        if (cnt == k) kthValue = root->val;
        inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return kthValue;
    }
};
