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
    int dfs(TreeNode* root, vector<int>& vi) {
        if (!root) return 0;
        
        int lDepth = dfs(root->left, vi);
        int rDepth = dfs(root->right, vi);
               
        // printf("node '%d': l=%d r=%d\n", root->val, lDepth, rDepth);
        
        vi[0] = max(vi[0], lDepth + rDepth);
        return max(lDepth, rDepth) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        vector<int> vi = {0};
        dfs(root, vi);
        return vi[0];
    }
};
