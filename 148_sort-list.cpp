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
    ListNode* merge(ListNode* l, ListNode* r) {
        if (!l && !r) return NULL;
        else if (!l || !r) return l ? l : r;
        
        if (l->val < r->val) {
            l->next = merge(l->next, r);
            return l;
        } else {
            r->next = merge(l, r->next);
            return r;
        }
    }
    
    ListNode* mergeSort(ListNode* head, int lo, int hi) {
        if (lo >= hi) { return head; }
        ListNode* prev = NULL;
        ListNode* cur = head;
        int mid = lo + (hi - lo) / 2;
        for (int i = lo; i <= mid; i++) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        auto l = mergeSort(head, lo, mid);
        auto r = mergeSort(cur, mid + 1, hi);
        return merge(l, r);
    }
public:
    ListNode* sortList(ListNode* head) {
        int sz = 0;
        for (auto node = head; node; node = node->next) {
            sz++;
        }
        return mergeSort(head, 0, sz);
    }
};
