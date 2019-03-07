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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<int> v;
        stack<TreeNode*> st;
        set<TreeNode*> visited;
        st.push(root);
        while (!st.empty()) {
            auto top = st.top();
            if (visited.find(top) == visited.end()) {
                v.push_back(top->val);
                visited.insert(top);
            }
            
            if (top->left && visited.find(top->left) == visited.end()) {
                st.push(top->left);
                continue;
            }
            
            st.pop();
            
            if (top->right && visited.find(top->right) == visited.end()) {
                st.push(top->right);
            }
        }
        return v;
    }
};
