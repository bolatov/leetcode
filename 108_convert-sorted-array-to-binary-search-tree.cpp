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
    TreeNode* toBst(vector<int>& v, int lo, int hi) {
        if (lo > hi) return NULL;
        int offset = ((hi - lo) % 2) ? 1 : 0;
        int mid = lo + (hi - lo) / 2 + offset;
        TreeNode* r = new TreeNode(v[mid]);
        r->left = toBst(v, lo, mid - 1);
        r->right = toBst(v, mid + 1, hi);
        return r;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { return toBst(nums, 0, nums.size() - 1); }
};