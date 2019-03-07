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
    vector<int> findMode(TreeNode* root) {
        if (!root) {return {};}
        map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int maxFreq = 0;
        while (!q.empty()) {
            TreeNode* tn = q.front();
            q.pop();
            
            if (!mp.count(tn->val)) mp[tn->val] = 0;
            mp[tn->val]++;
            maxFreq = max(maxFreq, mp[tn->val]);
            
            if (tn->left) {q.push(tn->left);}
            if (tn->right) {q.push(tn->right);}
        }
        vector<int> vi;
        for (auto kv : mp) {
            if (kv.second == maxFreq) vi.push_back(kv.first);
        }
        return vi;
    }
};
