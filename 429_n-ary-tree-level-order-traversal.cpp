/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> vvi;
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (vvi.size() < f.second) {
                vvi.push_back({});
            }
            vvi[vvi.size() - 1].push_back(f.first->val);
            for (auto child : f.first->children) {
                q.push({child, f.second + 1});
            }
        }
        return vvi;
    }
};
