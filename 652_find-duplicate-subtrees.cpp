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
    string walk(TreeNode* root, vector<TreeNode*>& vt, unordered_map<string, int>& mp) {
        if (!root) {return "()";}
        string l = walk(root->left, vt, mp);
        string r = walk(root->right, vt, mp);
        if (root->left) {
            if (!mp.count(l)) mp[l] = 0;
            mp[l]++;
            if (mp[l] == 2) vt.push_back(root->left);
        }
        if (root->right) {
            if (!mp.count(r)) mp[r] = 0;
            mp[r]++;
            if (mp[r] == 2) vt.push_back(root->right);
        }
        return "(" + to_string(root->val) + l + r + ")";
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) {return {};}
        vector<TreeNode*> vt;
        unordered_map<string, int> mp;
        walk(root, vt, mp);
        return vt;
    }
};
