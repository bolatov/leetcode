/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        
        queue<pair<TreeLinkNode*, int> > q;
        q.push({root, 0});
        pair<TreeLinkNode*, int> prev = {NULL, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            if (prev.second == p.second) {
                prev.first->next = p.first;
            }
            
            if (p.first->left) {
                q.push({p.first->left, p.second + 1});
            }
            if (p.first->right) {
                q.push({p.first->right, p.second + 1});
            }
            
            prev = p;
        }
    }
};
