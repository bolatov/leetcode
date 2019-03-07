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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *prev, *nxt, *en, *be, *tail, *tmp;
        
        int pos = 1;
        en = head;
        for (en = head; pos < m; pos++) {
            prev = en;
            en = en->next;
        }
        
        be = en;
        tail = NULL;
        while (pos < n) {
            tmp = be->next;
            nxt = tmp->next;
            be->next = tail;
            tail = be;
            be = tmp;
            pos++;
        }
        be->next = tail;
        en->next = nxt;
        
        if (m > 1) {
            prev->next = be;
        } else if (m == 1) {
            head = be;
        }
        
        return head;
    }
};
