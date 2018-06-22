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
    int getPosition(vector<int>& vi, int k, int be, int en) {
        while (be <= en) {
            if (vi[be] == k) return be;
            be++;
        }
        return -1;
    }

    TreeNode* build(vector<int>& pre, vector<int>& in, int idx, int be, int en) {
        if (be > en) return NULL;
        TreeNode* root = new TreeNode(pre[idx]);
        int pos = getPosition(in, pre[idx], be, en);
        root->left = build(pre, in, idx + 1, be, pos - 1);
        root->right = build(pre, in, idx + (pos - be) + 1, pos + 1, en);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return build(pre, in, 0, 0, in.size() - 1);
    }
};
