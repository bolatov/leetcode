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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {return {};}
        vector<int> vi;
        set<TreeNode*> visited;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* tn = st.top();
            if (tn->left && !visited.count(tn->left)) {
                st.push(tn->left);
                continue;
            }
            
            if (tn->right && !visited.count(tn->right)) {
                st.push(tn->right);
                continue;
            }
            
            st.pop();
            visited.insert(tn);
            vi.push_back(tn->val);
        }
        return vi;
    }
};
