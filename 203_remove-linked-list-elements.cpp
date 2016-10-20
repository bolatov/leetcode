/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        ListNode* h = head;
        while (h && h->val == val) {
            h = h->next;
        }
        if (!h) {
            return h;
        }
        h->next = removeElements(h->next, val);
        return h;
    }
};
