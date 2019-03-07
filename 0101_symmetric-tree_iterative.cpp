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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            auto n1 = q1.front();
            auto n2 = q2.front();
            q1.pop();
            q2.pop();
            if (!n1 && !n2) {
                continue;
            }
            if (!n1 || !n2) {
                return false;
            }
            if (n1->val != n2->val) {
                return false;
            }
            q1.push(n1->left);
            q1.push(n1->right);
            
            // push the right node first!
            q2.push(n2->right);
            q2.push(n2->left);
        }
        return q1.empty() && q2.empty();
    }
};
