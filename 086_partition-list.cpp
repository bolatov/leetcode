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
    ListNode* partition(ListNode* head, int x) {
        // Maintain two linked lists 
        //  l - Elements less than x
        //  r - Elements greater than or equal to x.
        //
        // Additionally, keep references to their
        // corresponing tail nodes (ltail, rtail).
        ListNode *l = NULL;
        ListNode *r = NULL;
        ListNode *ltail = NULL;
        ListNode *rtail = NULL;
        
        while (head) {
            ListNode* nxt = head->next;
            head->next = NULL;
            if (head->val < x) {
                if (l) {
                    ltail->next = head;
                    ltail = ltail->next;
                } else {
                    l = ltail = head;
                }
            } else {
                if (r) {
                    rtail->next = head;
                    rtail = rtail->next;
                } else {
                    r = rtail = head;
                }
            }
            head = nxt;
        }
        
        // Check if there are nodes where node value
        // is less than x.
        if (ltail) {
            ltail->next = r;
            return l;
        }
        
        // Otherwise, there are only nodes with values
        // greater than or equal to x.
        return r;
    }
};
