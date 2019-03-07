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
    int getPosition(vector<int>& vi, int be, int en, int k) {
        while (be <= en) {
            if (vi[be] == k) return be;
            be++;
        }
        return -1;
    }
    TreeNode* build(vector<int>& in, vector<int>& post, int idx, int be, int en) {
        if (be > en) return NULL;
        TreeNode* root = new TreeNode(post[idx]);
        int pos = getPosition(in, be, en, root->val);
        root->left = build(in, post, idx - (en - pos + 1), be, pos - 1);
        root->right = build(in, post, idx - 1, pos + 1, en);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return build(in, post, post.size() - 1, 0, post.size() - 1);
    }
};
