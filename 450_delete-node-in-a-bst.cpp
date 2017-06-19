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
    TreeNode* minValueNode(TreeNode* root) {
        if (!root || !root->left) {
            return root;
        }
        return minValueNode(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                auto temp = root->right;
                free(root);
                root = temp;
            } else if (!root->right) {
                auto temp = root->left;
                free(root);
                root = temp;
            } else {
                auto t = minValueNode(root->right);
                root->val = t->val;
                root->right = deleteNode(root->right, t->val);
            }
        }
        
        return root;
    }
};
