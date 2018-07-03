/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
private:
    TreeNode* toBST(ListNode* head, int lo, int hi) {
        if (lo > hi) return NULL;
        auto prev = head;
        auto cur = head;
        int mid = lo + (hi - lo) / 2;
        for (int i = lo; i < mid; i++) {
            prev = cur;
            cur = cur->next;
        }
        TreeNode* root = new TreeNode(cur->val);
        root->left = toBST(head, lo, mid - 1);
        root->right = toBST(cur->next, mid + 1, hi);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int sz = 0;
        for (auto node = head; node; node = node->next) sz++;
        int lo = 0, hi = sz - 1;
        return toBST(head, lo, hi);
    }
};
