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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        // get size
        int size = 0;
        for (ListNode* node = head; node; node = node->next) size++;
        int mid = (size / 2) + (size % 2);
        
        // split into left & right
        ListNode* left = head;
        ListNode* right = head;
        ListNode* prev;
        for (int i = 0; i < mid; i++) {
            prev = right;
            right = right->next;
        }
        prev->next = NULL;
        
        // reverse the right linked list
        ListNode *tail = NULL, *nxt;
        for (ListNode* node = right; node;) {
            nxt = node->next;
            node->next = tail;
            tail = node;
            right = node;
            node = nxt;
        }
        
        // merge left & right
        ListNode *lnxt, *rnxt;
        while (left && right) {
            lnxt = left->next;
            rnxt = right->next;
            left->next = right;
            left->next->next = lnxt;
            right = rnxt;
            left = lnxt;
        }
    }
};
