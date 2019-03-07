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
    TreeNode* f(TreeNode* node) {
        if (!node->left && !node->right) {
            return node;
        }
        
        if (node->left) {
            TreeNode* br = f(node->left);
            br->right = node->right;
            node->right = node->left;
            node->left = NULL;
            
            if (br->right) {
                return f(br->right);
            }
        } 
        
        return f(node->right);
    }
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        
        if (root->left) {
            TreeNode* br = f(root->left);
            br->right = root->right;
            root->right = root->left;
            
            flatten(br->right);
            
            root->left = NULL;
        } else {
            flatten(root->right);
        }
    }
};
