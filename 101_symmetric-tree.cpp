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
    bool check(TreeNode* t1, TreeNode* t2) {
        // both are null
        if (!t1 && !t2) {
            return true;
        }
        
        // one of them is null
        if (!t1 || !t2) {
            return false;
        }
        
        // check  values
        if (t1->val != t2->val) {
            return false;
        }
        
        // check children mirrored
        return check(t1->left, t2->right) && check(t1->right, t2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return check(root->left, root->right);
    }
};
