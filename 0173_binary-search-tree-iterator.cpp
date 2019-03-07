/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> parents;
    
    void dfs(TreeNode *node) {
        if (!node) return;
        parents.push(node);
        dfs(node->left);
    }
public:
    BSTIterator(TreeNode *root) {
        dfs(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !parents.empty();
    }

    /** @return the next smallest number */
    int next() {
        int nxt = -1;
        if (!parents.empty()) {
            TreeNode* tp = parents.top();
            nxt = tp->val;
            parents.pop();
            dfs(tp->right);
        }
        return nxt;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
