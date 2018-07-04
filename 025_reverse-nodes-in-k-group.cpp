/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool checkSize(ListNode* head, int k) {
        int sz = 0;
        while (head) {
            sz++;
            head = head->next;
            if (sz >= k) return true;
        }
        return false;
    }
    ListNode* reverse(ListNode* head, int n) {
        if (1 == n || !checkSize(head, n)) return head;
        ListNode *nxt, *en, *be, *tail, *tmp;
        
        int pos = 1;
        en = head;        
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
        
        return be;
    }
    ListNode* getKth(ListNode* head, int k) {
        int sz = 0;
        while (head) {
            if (++sz == k) return head;
            head = head->next;
        }
        return NULL;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        head = reverse(head, k);
        ListNode* kth = getKth(head, k);
        if (kth) {
            kth->next = reverseKGroup(kth->next, k);
        }
        return head;
    }
};
