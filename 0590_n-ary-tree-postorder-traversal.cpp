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
    vector<int> postorder(Node* root) {
        if (!root) return {};
        stack<Node*> st, rev;
        st.push(root);
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            rev.push(top);
            
            for (auto it = top->children.begin(); it != top->children.end(); it++) {
                st.push(*it);
            }
        }
        
        int i = 0;
        vector<int> vi(rev.size());
        while (!rev.empty()) {
            auto top = rev.top();
            rev.pop();
            vi[i++] = top->val;
        }
        return vi;
    }
};
