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
    vector<TreeNode*> solve(int be, int en) {
        if (be > en) { return {}; } 
        if (be == en) {
            vector<TreeNode*> vt = {new TreeNode(be)};
            return vt;
        }
        
        vector<TreeNode*> vt;
        for (int i = be; i <= en; i++) {
            auto left = solve(be, i - 1);
            auto right = solve(i + 1, en);
                       
            if (left.empty() || right.empty()) {
                for (int j = 0; j < left.size(); j++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left[j];
                    vt.push_back(node);
                }
                for (int j = 0; j < right.size(); j++) {
                    TreeNode* node = new TreeNode(i);
                    node->right = right[j];
                    vt.push_back(node);
                }
                continue;
            }
            
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    auto l = left[j];
                    auto r = right[k];
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    vt.push_back(node);
                }
            }
        }
        
        return vt;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
