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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<int> v;
        stack<TreeNode*> st;
        st.push(root);
        set<TreeNode*> visited;
        while (!st.empty()) {
            auto top = st.top();
            if (top->left && visited.find(top->left) == visited.end()) {
                st.push(top->left);
                continue;
            }
            
            v.push_back(top->val);
            visited.insert(top);
            st.pop();
            
            if (top->right && visited.find(top->right) == visited.end()) {
                st.push(top->right);
            }
        }
        
        return v;
    }
};
