/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n)
class Solution {
private:
    int cnt = 0;
    int kthValue = -1;
    void inorder(TreeNode* root, const int k) {
        if (!root) return;
        inorder(root->left, k);
        cnt++;
        if (cnt == k) kthValue = root->val;
        inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return kthValue;
    }
};

// O(log²n) using stack
class Solution {
public:
    int getSize(TreeNode* root) {
        if (!root) {return 0;}
        stack<TreeNode*> st;
        st.push(root);
        int cnt = 0;
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            cnt++;
            if (top->left) st.push(top->left);
            if (top->right) st.push(top->right);
        }
        return cnt;
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            int size = getSize(top->left) + 1;
            if (size == k) return top->val;
            else if (size > k) st.push(top->left);
            else {
                k -= size;
                st.push(top->right);
            }
        }
        return -1;
    }
};
