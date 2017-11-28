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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {        
        if (!root) {
            return root;
        }
        
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            if (p.second + 1 == d) {
                TreeNode* leftChild = new TreeNode(v);
                TreeNode* rightChild = new TreeNode(v);
                
                leftChild->left = p.first->left;
                rightChild->right = p.first->right;
                p.first->left = leftChild;
                p.first->right = rightChild;
                
                continue;
            }
            
            if (p.first->left) {
                q.push({p.first->left, p.second + 1});
            }
            
            if (p.first->right) {
                q.push({p.first->right, p.second + 1});
            }
        }
        
        return root;
    }
};
