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
    int dfs(TreeNode* node, map<int, int>& mp) {      
        int left = 0, right = 0;
        if (node->left) {
            left = dfs(node->left, mp);
            if (mp.find(left) == mp.end()) {
                mp[left] = 0;
            }
            mp[left] = mp[left] + 1;
        }
        
        if (node->right) {
            right = dfs(node->right, mp);
            if (mp.find(right) == mp.end()) {
                mp[right] = 0;
            }
            mp[right] = mp[right] + 1;
        }
        
        return left + right + node->val;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        map<int, int> mp;
        int sum = dfs(root, mp);
        if (mp.find(sum) == mp.end()) {
            mp[sum] = 0;
        }
        mp[sum] = mp[sum] + 1;
        
        int freq = 0;
        vector<int> v;
        for (auto& kv : mp) {
            if (kv.second == freq) {
                v.push_back(kv.first);
            } else if (kv.second > freq) {
                freq = kv.second;
                v.clear();
                v.push_back(kv.first);
            }
        }
        
        
        return v;
    }
};