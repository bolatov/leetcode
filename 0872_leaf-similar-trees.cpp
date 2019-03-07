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
    void getLeafValues(TreeNode* root, list<int>& lst) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            lst.push_back(root->val);
        }
            
        getLeafValues(root->left, lst);
        getLeafValues(root->right, lst);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        list<int> li, lj;
        getLeafValues(root1, li);
        getLeafValues(root2, lj);
        if (li.size() != lj.size()) {
            return false;
        }
        for (auto i = li.begin(), j = lj.begin(); i != li.end() && j != lj.end(); i++, j++) {
            if (*i != *j) return false;
        }
        return true;
    }
};
