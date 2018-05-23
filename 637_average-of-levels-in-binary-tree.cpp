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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vd;
        if (!root) {return vd;}
        
        queue<pair<TreeNode*, int>> q;
        int cur = 0;
        q.push({root, cur});
        double sum = 0.0;
        int cnt = 0;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if (cur < p.second) {
                vd.push_back(sum / (double) cnt);
                sum = 0;
                cnt = 0;
                cur++;
            }
            
            cnt++;
            sum += p.first->val;
        
            
            if (p.first->left) {
                q.push({p.first->left, p.second + 1});
            }
            if (p.first->right) {
                q.push({p.first->right, p.second + 1});
            }
        }
        vd.push_back(sum / (double) cnt);
        return vd;
    }
};