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
    
    ListNode* merge(vector<ListNode*>& vl, int lo, int hi) {
        if (lo > hi) return NULL;
        if (lo == hi) return vl[lo];
        int mid = lo + (hi - lo) / 2;
        ListNode* l = merge(vl, lo, mid);
        ListNode* r = merge(vl, mid + 1, hi);
        if (!l && !r) return NULL;
        if (!l || !r) return l ? l : r;
        
        ListNode *nxt, *head, *tail;
        if (l->val < r->val) {
            nxt = l->next;
            head = l;
            l = nxt;
        } else {
            nxt = r->next;
            head = r;
            r = nxt;
        }
        tail = head;
        
        while (l && r) {
            if (l->val < r->val) {
                nxt = l->next;
                tail->next = l;
                l = nxt;
            } else {
                nxt = r->next;
                tail->next = r;
                r = nxt;
            }
            tail = tail->next;

        }
        tail->next = l ? l : r;
        tail = tail->next;
        tail = NULL;
        
        return head;
    }

public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
