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
    void dfs(TreeNode* root, vector<int>& vi) {
        if (!root) return;
        
        dfs(root->left, vi);
        vi.push_back(root->val);
        dfs(root->right, vi);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vi;
        dfs(root, vi);
        int minDiff = abs(vi[0] - vi[vi.size() - 1]);
        for (int i = 1; i < vi.size(); i++) 
            minDiff = min(abs(vi[i] - vi[i - 1]), minDiff);
        return minDiff;
    }
};
