class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode* i1 = head;
        ListNode* i2 = head;
        for (int i = 0; i < n; i++) {
            i2 = i2->next;
        }
        if (!i2) return head->next;
        
        while (i2->next) {
            i1 = i1->next;
            i2 = i2->next;
        }
        i1->next = i1->next->next;
        return head;
    }
};
