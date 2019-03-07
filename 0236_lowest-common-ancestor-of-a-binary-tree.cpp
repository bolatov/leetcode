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
    bool find(TreeNode* root, TreeNode* c) {
        if (root == c) {
            return true;
        }
        
        if (!root || (!root->left && !root->right)) {
            return false;
        }
            
        return find(root->left, c) || find(root->right, c);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        
        bool isPInLeftBranch = find(root->left, p);
        bool isQInRightBranch = find(root->right, q);
        if (isPInLeftBranch == isQInRightBranch) {
            return root;
        }
        
        return isPInLeftBranch ? lowestCommonAncestor(root->left, p, q) :
            lowestCommonAncestor(root->right, p, q);
    }
};
