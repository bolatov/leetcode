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
    int getHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            root = root->left;
            h++;
        }
        return h;
    }
    bool check(TreeNode* root, int height, int path) {
        for (int i = height - 1; i >= 0; i--) {
            root = (1 << i) & path ? root->right : root->left;
            if (!root) return false;
        }
        return true;
    }
    int countNodes(TreeNode* root) {
        if (!root) {return 0;}
        int height = getHeight(root);
        int nodes = 1 << (height - 1);
        int lo = 0, hi = nodes - 1;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            bool hasValue = check(root, height - 1, mid);
            if (hasValue) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return nodes + ans;
    }
};
