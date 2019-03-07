/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> vi;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            vi.push_back(top->val);
            
            for (auto it = top->children.rbegin(); it != top->children.rend(); it++) {
                st.push(*it);
            }
        }
        return vi;
    }
};
