/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {return "[]";}
        string s = "[";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto tn = q.front();
            q.pop();
            
            s += s.size() == 1 ? "" : ",";
            if (!tn) {
                s += "#";
                continue;
            }
            
            s += to_string(tn->val);
            q.push(tn->left);
            q.push(tn->right);
        }

        // remove trailing null values
        int en = s.size() - 1;
        for (; s[en] == '#'; en -= 2);
        s.erase(s.begin() + en + 1, s.end());
        
        return s + "]";
    }
    
    pair<TreeNode*, int> nextNode(string& data, int i) {
        if (i + 1 >= data.size()) return {NULL, data.size()};
        
        size_t pos = data.find(",", i);
        if (pos == string::npos) pos = data.find("]");
        string s = data.substr(i, pos - i);
        
        TreeNode* tn = (s != "#") ? new TreeNode(stoi(s)) : NULL;
        return {tn, pos};
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;
        auto nxt = nextNode(data, 1);
        
        TreeNode* root = nxt.first;
        int pos = nxt.second;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty() && pos < data.size()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!node) continue;
            
            auto l = nextNode(data, pos + 1);
            node->left = l.first;
            pos = l.second;
            
            auto r = nextNode(data, pos + 1);
            node->right = r.first;
            pos = r.second;
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};
