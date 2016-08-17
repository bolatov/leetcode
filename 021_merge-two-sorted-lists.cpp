class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = NULL;
        if (!l1 && !l2) return h;

        ListNode* lst = h;
        while (l1 || l2) {
            ListNode* nxt;

            if ((l1 ? l1->val : INT_MAX) < (l2 ? l2->val : INT_MAX)) {
                nxt = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                nxt = new ListNode(l2->val);
                l2 = l2->next;
            }

            if (!lst) {
                h = nxt;
                lst = h;
            } else {
                lst->next = nxt;
                lst = lst->next;
             }
        }

        return h;
    }
};
