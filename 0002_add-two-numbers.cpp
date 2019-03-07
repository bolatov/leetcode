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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(-1);
        ListNode* s = sum;
        int q = 0;
        while (l1 && l2) {
            int k = l1->val + l2->val + q;
            q = k / 10;
            k %= 10;
            s->next = new ListNode(k);;
            s = s->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        for (auto l : {l1, l2}) {
            while (l) {
                int k = l->val + q;
                q = k / 10;
                k %= 10;
                s->next = new ListNode(k);
                s = s->next;
                l = l->next;
            }
        }
        
        if (q > 0) {
            s->next = new ListNode(q);
            s = s->next;
        }
        
        return sum->next;
    }
};
