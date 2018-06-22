/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// OBSERVATIONS:
// 1. The very first element in preorder traversal is root element 
//      followed by left sub-tree and right sub-tree.
// 2. In inorder traversal array, the root element is in the middle,
//      where elements to the left belong to the left sub-tree and
//      elements to the right belong to the right sub-tree.
// 
//  e.g.
//      PRE: [(1),2,4,5,3,6,7]
//      INO: [4,2,5,(1),6,3,7]
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
